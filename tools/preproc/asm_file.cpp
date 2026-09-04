// Copyright(c) 2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdio>
#include <cstdarg>
#include <map>
#include <stdexcept>
#include <vector>
#include "preproc.h"
#include "asm_file.h"
#include "char_util.h"
#include "utf8.h"
#include "string_parser.h"
#include "../../include/constants/characters.h"
#include "io.h"

// The game's braille font stores cells in row-major dot order, whereas
// Unicode Braille uses the conventional column-major dot order.  This lets
// .braille accept U+2800--U+283F literals without changing the regular text
// charmap or assuming a kana-to-byte mapping.
static unsigned char EncodeUnicodeBrailleCell(std::int32_t codepoint)
{
    unsigned char dots = codepoint - 0x2800;

    return (dots & 0x01)
        | ((dots & 0x02) << 1)
        | ((dots & 0x04) << 2)
        | ((dots & 0x08) >> 2)
        | ((dots & 0x10) >> 1)
        | (dots & 0x20);
}

static std::int32_t NormalizeJapaneseKana(std::int32_t codepoint)
{
    if (codepoint >= 0x30A1 && codepoint <= 0x30F6)
        return codepoint - 0x60;

    return codepoint;
}

// The Japanese Braille source owner is written as readable kana. This is
// intentionally a closed mapping for the characters covered by its ROM-backed
// regression fixtures; unsupported Japanese text must remain a hard error.
// Katakana is normalized to its hiragana counterpart so either conventional
// phonetic spelling is accepted without changing the emitted cells.
static const std::vector<unsigned char> *GetJapaneseBrailleCells(std::int32_t codepoint)
{
    static const std::map<std::int32_t, std::vector<unsigned char>> sEncoding =
    {
        { 0x3042, { EncodeUnicodeBrailleCell(0x2801) } }, // あ
        { 0x3044, { EncodeUnicodeBrailleCell(0x2803) } }, // い
        { 0x3046, { EncodeUnicodeBrailleCell(0x2809) } }, // う
        { 0x3048, { EncodeUnicodeBrailleCell(0x280B) } }, // え
        { 0x304A, { EncodeUnicodeBrailleCell(0x280A) } }, // お
        { 0x304B, { EncodeUnicodeBrailleCell(0x2821) } }, // か
        { 0x304D, { EncodeUnicodeBrailleCell(0x2823) } }, // き
        { 0x304F, { EncodeUnicodeBrailleCell(0x2829) } }, // く
        { 0x3051, { EncodeUnicodeBrailleCell(0x282B) } }, // け
        { 0x3053, { EncodeUnicodeBrailleCell(0x282A) } }, // こ
        { 0x3055, { EncodeUnicodeBrailleCell(0x2831) } }, // さ
        { 0x3057, { EncodeUnicodeBrailleCell(0x2833) } }, // し
        { 0x3059, { EncodeUnicodeBrailleCell(0x2839) } }, // す
        { 0x305B, { EncodeUnicodeBrailleCell(0x283B) } }, // せ
        { 0x305D, { EncodeUnicodeBrailleCell(0x283A) } }, // そ
        { 0x305F, { EncodeUnicodeBrailleCell(0x2815) } }, // た
        { 0x3061, { EncodeUnicodeBrailleCell(0x2817) } }, // ち
        { 0x3064, { EncodeUnicodeBrailleCell(0x281D) } }, // つ
        { 0x3066, { EncodeUnicodeBrailleCell(0x281F) } }, // て
        { 0x3068, { EncodeUnicodeBrailleCell(0x281E) } }, // と
        { 0x306A, { EncodeUnicodeBrailleCell(0x2805) } }, // な
        { 0x306B, { EncodeUnicodeBrailleCell(0x2807) } }, // に
        { 0x306C, { EncodeUnicodeBrailleCell(0x280D) } }, // ぬ
        { 0x306D, { EncodeUnicodeBrailleCell(0x280F) } }, // ね
        { 0x306E, { EncodeUnicodeBrailleCell(0x280E) } }, // の
        { 0x306F, { EncodeUnicodeBrailleCell(0x2825) } }, // は
        { 0x3072, { EncodeUnicodeBrailleCell(0x2827) } }, // ひ
        { 0x3075, { EncodeUnicodeBrailleCell(0x282D) } }, // ふ
        { 0x3078, { EncodeUnicodeBrailleCell(0x282F) } }, // へ
        { 0x307B, { EncodeUnicodeBrailleCell(0x282E) } }, // ほ
        { 0x307E, { EncodeUnicodeBrailleCell(0x2835) } }, // ま
        { 0x307F, { EncodeUnicodeBrailleCell(0x2837) } }, // み
        { 0x3080, { EncodeUnicodeBrailleCell(0x283D) } }, // む
        { 0x3081, { EncodeUnicodeBrailleCell(0x283F) } }, // め
        { 0x3082, { EncodeUnicodeBrailleCell(0x283E) } }, // も
        { 0x3084, { EncodeUnicodeBrailleCell(0x280C) } }, // や
        { 0x3086, { EncodeUnicodeBrailleCell(0x282C) } }, // ゆ
        { 0x3088, { EncodeUnicodeBrailleCell(0x281C) } }, // よ
        { 0x3089, { EncodeUnicodeBrailleCell(0x2811) } }, // ら
        { 0x308A, { EncodeUnicodeBrailleCell(0x2813) } }, // り
        { 0x308B, { EncodeUnicodeBrailleCell(0x2819) } }, // る
        { 0x308C, { EncodeUnicodeBrailleCell(0x281B) } }, // れ
        { 0x308D, { EncodeUnicodeBrailleCell(0x281A) } }, // ろ
        { 0x308F, { EncodeUnicodeBrailleCell(0x2804) } }, // わ
        { 0x3092, { EncodeUnicodeBrailleCell(0x2814) } }, // を
        { 0x3093, { EncodeUnicodeBrailleCell(0x2834) } }, // ん
        { 0x304C, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2821) } }, // が
        { 0x304E, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2823) } }, // ぎ
        { 0x3050, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2829) } }, // ぐ
        { 0x3052, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x282B) } }, // げ
        { 0x3054, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x282A) } }, // ご
        { 0x3056, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2831) } }, // ざ
        { 0x3058, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2833) } }, // じ
        { 0x305A, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2839) } }, // ず
        { 0x305C, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x283B) } }, // ぜ
        { 0x305E, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x283A) } }, // ぞ
        { 0x3060, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2815) } }, // だ
        { 0x3062, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2817) } }, // ぢ
        { 0x3065, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x281D) } }, // づ
        { 0x3067, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x281F) } }, // で
        { 0x3069, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x281E) } }, // ど
        { 0x3070, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2825) } }, // ば
        { 0x3073, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x2827) } }, // び
        { 0x3076, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x282D) } }, // ぶ
        { 0x3079, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x282F) } }, // べ
        { 0x307C, { EncodeUnicodeBrailleCell(0x2810), EncodeUnicodeBrailleCell(0x282E) } }, // ぼ
        { 0x3071, { EncodeUnicodeBrailleCell(0x2820), EncodeUnicodeBrailleCell(0x2825) } }, // ぱ
        { 0x3074, { EncodeUnicodeBrailleCell(0x2820), EncodeUnicodeBrailleCell(0x2827) } }, // ぴ
        { 0x3077, { EncodeUnicodeBrailleCell(0x2820), EncodeUnicodeBrailleCell(0x282D) } }, // ぷ
        { 0x307A, { EncodeUnicodeBrailleCell(0x2820), EncodeUnicodeBrailleCell(0x282F) } }, // ぺ
        { 0x307D, { EncodeUnicodeBrailleCell(0x2820), EncodeUnicodeBrailleCell(0x282E) } }, // ぽ
        { 0x3063, { EncodeUnicodeBrailleCell(0x2802) } }, // っ
        { 0x30FC, { EncodeUnicodeBrailleCell(0x2812) } }, // ー
    };

    auto it = sEncoding.find(NormalizeJapaneseKana(codepoint));
    if (it == sEncoding.end())
        return nullptr;

    return &it->second;
}

static const std::vector<unsigned char> *GetJapaneseBrailleDigraph(
    std::int32_t firstCodepoint, std::int32_t secondCodepoint)
{
    static const std::vector<unsigned char> sSho =
    {
        EncodeUnicodeBrailleCell(0x2808),
        EncodeUnicodeBrailleCell(0x283A),
    };

    if (NormalizeJapaneseKana(firstCodepoint) == 0x3057
     && NormalizeJapaneseKana(secondCodepoint) == 0x3087)
        return &sSho;

    return nullptr;
}

AsmFile::AsmFile(std::string filename, bool isStdin, bool doEnum) : m_filename(filename)
{
    m_buffer = ReadFileToBuffer(filename.c_str(), isStdin, &m_size);
    m_doEnum = doEnum;

    m_pos = 0;
    m_lineNum = 1;
    m_lineStart = 0;

    RemoveComments();
}

AsmFile::AsmFile(AsmFile&& other) : m_filename(std::move(other.m_filename))
{
    m_buffer = other.m_buffer;
    m_doEnum = other.m_doEnum;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_lineNum = other.m_lineNum;
    m_lineStart = other.m_lineStart;

    other.m_buffer = nullptr;
}

AsmFile::~AsmFile()
{
    if (m_size > 0) delete[] m_buffer;
}

// Removes comments to simplify further processing.
// It stops upon encountering a null character,
// which may or may not be the end of file marker.
// If it's not, the error will be caught later.
void AsmFile::RemoveComments()
{
    long pos = 0;
    char stringChar = 0;

    for (;;)
    {
        if (m_buffer[pos] == 0)
            return;

        if (stringChar != 0)
        {
            if (m_buffer[pos] == '\\' && m_buffer[pos + 1] == stringChar)
            {
                pos += 2;
            }
            else
            {
                if (m_buffer[pos] == stringChar)
                    stringChar = 0;
                pos++;
            }
        }
        else if (m_buffer[pos] == '@' && (pos == 0 || m_buffer[pos - 1] != '\\'))
        {
            while (m_buffer[pos] != '\n' && m_buffer[pos] != 0)
                m_buffer[pos++] = ' ';
        }
        else if (m_buffer[pos] == '/' && m_buffer[pos + 1] == '*')
        {
            m_buffer[pos++] = ' ';
            m_buffer[pos++] = ' ';

            for (;;)
            {
                if (m_buffer[pos] == 0)
                    return;

                if (m_buffer[pos] == '*' && m_buffer[pos + 1] == '/')
                {
                    m_buffer[pos++] = ' ';
                    m_buffer[pos++] = ' ';
                    break;
                }
                else
                {
                    if (m_buffer[pos] != '\n')
                        m_buffer[pos] = ' ';
                    pos++;
                }
            }
        }
        else
        {
            if (m_buffer[pos] == '"' || m_buffer[pos] == '\'')
                stringChar = m_buffer[pos];
            pos++;
        }
    }
}

// Checks if we're at a particular directive and if so, consumes it.
// Returns whether the directive was found.
bool AsmFile::CheckForDirective(std::string name)
{
    long i;
    long length = static_cast<long>(name.length());

    for (i = 0; i < length && m_pos + i < m_size; i++)
        if (name[i] != m_buffer[m_pos + i])
            return false;

    if (i < length)
        return false;

    m_pos += length;

    return true;
}

// Checks if we're at a known directive and if so, consumes it.
// Returns which directive was found.
Directive AsmFile::GetDirective()
{
    SkipWhitespace();

    if (CheckForDirective(".include"))
        return Directive::Include;
    else if (CheckForDirective(".string"))
        return Directive::String;
    else if (CheckForDirective(".braille"))
        return Directive::Braille;
    else if (CheckForDirective("enum"))
        return Directive::Enum;
    else if (CheckForDirective(".macro"))
        return Directive::Macro;
    else
        return Directive::Unknown;
}

// Checks if we're at label that ends with '::'.
// Returns the name if so and an empty string if not.
std::string AsmFile::GetGlobalLabel()
{
    long start = m_pos;
    long pos = m_pos;

    if (IsIdentifierStartingChar(m_buffer[pos]))
    {
        pos++;

        while (IsIdentifierChar(m_buffer[pos]))
            pos++;
    }

    if (m_buffer[pos] == ':' && m_buffer[pos + 1] == ':')
    {
        m_pos = pos + 2;
        ExpectEmptyRestOfLine();
        return std::string(&m_buffer[start], pos - start);
    }

    return std::string();
}

// Skips tabs and spaces.
void AsmFile::SkipWhitespace()
{
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
        m_pos++;
}

// Reads include path.
std::string AsmFile::ReadPath()
{
    SkipWhitespace();

    if (m_buffer[m_pos] != '"')
        RaiseError("expected file path");

    m_pos++;

    int length = 0;
    long startPos = m_pos;

    while (m_buffer[m_pos] != '"')
    {
        unsigned char c = m_buffer[m_pos++];

        if (c == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in include string");
            else
                RaiseError("unexpected null character in include string");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in include string", c);

        // Don't bother allowing any escape sequences.
        if (c == '\\')
        {
            c = m_buffer[m_pos];
            RaiseError("unexpected escape '\\%c' in include string", c);
        }

        length++;

        if (length > kMaxPath)
            RaiseError("path is too long");
    }

    m_pos++; // Go past the right quote.

    ExpectEmptyRestOfLine();

    return std::string(&m_buffer[startPos], length);
}

// Reads a charmap string.
int AsmFile::ReadString(unsigned char* s)
{
    SkipWhitespace();

    int length;
    StringParser stringParser(m_buffer, m_size);

    try
    {
        m_pos += stringParser.ParseString(m_pos, s, length);
    }
    catch (std::runtime_error& e)
    {
        RaiseError(e.what());
    }

    SkipWhitespace();

    if (ConsumeComma())
    {
        SkipWhitespace();
        int padLength = ReadPadLength();

        while (length < padLength)
        {
            s[length++] = CHAR_SPACE;
        }
    }

    ExpectEmptyRestOfLine();

    return length;
}

void AsmFile::VerifyStringLength(int length)
{
    if (length == kMaxStringLength)
        RaiseError("mapped string longer than %d bytes", kMaxStringLength);
}

int AsmFile::ReadBraille(unsigned char* s)
{
    static std::map<char, unsigned char> encoding =
    {
        { 'A', BRAILLE_CHAR_A },
        { 'B', BRAILLE_CHAR_B },
        { 'C', BRAILLE_CHAR_C },
        { 'D', BRAILLE_CHAR_D },
        { 'E', BRAILLE_CHAR_E },
        { 'F', BRAILLE_CHAR_F },
        { 'G', BRAILLE_CHAR_G },
        { 'H', BRAILLE_CHAR_H },
        { 'I', BRAILLE_CHAR_I },
        { 'J', BRAILLE_CHAR_J },
        { 'K', BRAILLE_CHAR_K },
        { 'L', BRAILLE_CHAR_L },
        { 'M', BRAILLE_CHAR_M },
        { 'N', BRAILLE_CHAR_N },
        { 'O', BRAILLE_CHAR_O },
        { 'P', BRAILLE_CHAR_P },
        { 'Q', BRAILLE_CHAR_Q },
        { 'R', BRAILLE_CHAR_R },
        { 'S', BRAILLE_CHAR_S },
        { 'T', BRAILLE_CHAR_T },
        { 'U', BRAILLE_CHAR_U },
        { 'V', BRAILLE_CHAR_V },
        { 'W', BRAILLE_CHAR_W },
        { 'X', BRAILLE_CHAR_X },
        { 'Y', BRAILLE_CHAR_Y },
        { 'Z', BRAILLE_CHAR_Z },
        { 'a', BRAILLE_CHAR_A },
        { 'b', BRAILLE_CHAR_B },
        { 'c', BRAILLE_CHAR_C },
        { 'd', BRAILLE_CHAR_D },
        { 'e', BRAILLE_CHAR_E },
        { 'f', BRAILLE_CHAR_F },
        { 'g', BRAILLE_CHAR_G },
        { 'h', BRAILLE_CHAR_H },
        { 'i', BRAILLE_CHAR_I },
        { 'j', BRAILLE_CHAR_J },
        { 'k', BRAILLE_CHAR_K },
        { 'l', BRAILLE_CHAR_L },
        { 'm', BRAILLE_CHAR_M },
        { 'n', BRAILLE_CHAR_N },
        { 'o', BRAILLE_CHAR_O },
        { 'p', BRAILLE_CHAR_P },
        { 'q', BRAILLE_CHAR_Q },
        { 'r', BRAILLE_CHAR_R },
        { 's', BRAILLE_CHAR_S },
        { 't', BRAILLE_CHAR_T },
        { 'u', BRAILLE_CHAR_U },
        { 'v', BRAILLE_CHAR_V },
        { 'w', BRAILLE_CHAR_W },
        { 'x', BRAILLE_CHAR_X },
        { 'y', BRAILLE_CHAR_Y },
        { 'z', BRAILLE_CHAR_Z },
        { '0', BRAILLE_CHAR_0 },
        { '1', BRAILLE_CHAR_1 },
        { '2', BRAILLE_CHAR_2 },
        { '3', BRAILLE_CHAR_3 },
        { '4', BRAILLE_CHAR_4 },
        { '5', BRAILLE_CHAR_5 },
        { '6', BRAILLE_CHAR_6 },
        { '7', BRAILLE_CHAR_7 },
        { '8', BRAILLE_CHAR_8 },
        { '9', BRAILLE_CHAR_9 },
        { ' ', BRAILLE_CHAR_SPACE },
        { ',', BRAILLE_CHAR_COMMA },
        { '.', BRAILLE_CHAR_PERIOD },
        { '?', BRAILLE_CHAR_QUESTION_MARK },
        { '!', BRAILLE_CHAR_EXCL_MARK },
        { ':', BRAILLE_CHAR_COLON },
        { ';', BRAILLE_CHAR_SEMICOLON },
        { '-', BRAILLE_CHAR_HYPHEN },
        { '/', BRAILLE_CHAR_SLASH },
        { '(', BRAILLE_CHAR_PAREN },
        { ')', BRAILLE_CHAR_PAREN },
        { '\'', BRAILLE_CHAR_APOSTROPHE },
        { '#', BRAILLE_CHAR_NUMBER },
        { '$', EOS },
    };

    SkipWhitespace();

    int length = 0;

    if (m_buffer[m_pos] != '"')
        RaiseError("expected braille string literal");

    m_pos++;

    bool inNumber = false;
    while (m_buffer[m_pos] != '"')
    {
        if (m_buffer[m_pos] == '\\' && m_buffer[m_pos + 1] == 'n')
        {
            VerifyStringLength(length);
            s[length++] = CHAR_NEWLINE;
            m_pos += 2;
        }
        else
        {
            auto unicodeChar = DecodeUtf8(&m_buffer[m_pos]);
            if (unicodeChar.code >= 0x2800 && unicodeChar.code <= 0x283F)
            {
                VerifyStringLength(length);
                s[length++] = EncodeUnicodeBrailleCell(unicodeChar.code);
                m_pos += unicodeChar.encodingLength;
                continue;
            }

            auto nextUnicodeChar = DecodeUtf8(&m_buffer[m_pos + unicodeChar.encodingLength]);
            const auto *japaneseDigraph = GetJapaneseBrailleDigraph(
                unicodeChar.code, nextUnicodeChar.code);
            if (japaneseDigraph != nullptr)
            {
                for (unsigned char cell : *japaneseDigraph)
                {
                    VerifyStringLength(length);
                    s[length++] = cell;
                }

                m_pos += unicodeChar.encodingLength + nextUnicodeChar.encodingLength;
                continue;
            }

            const auto *japaneseCells = GetJapaneseBrailleCells(unicodeChar.code);
            if (japaneseCells != nullptr)
            {
                for (unsigned char cell : *japaneseCells)
                {
                    VerifyStringLength(length);
                    s[length++] = cell;
                }

                m_pos += unicodeChar.encodingLength;
                continue;
            }

            char c = m_buffer[m_pos];

            if (encoding.count(c) == 0)
            {
                if (unicodeChar.code > 0x7F)
                    RaiseError("Unicode character U+%04X not valid in braille string", unicodeChar.code);
                if (IsAsciiPrintable(c))
                    RaiseError("character '%c' not valid in braille string", m_buffer[m_pos]);
                else
                    RaiseError("character '\\x%02X' not valid in braille string", m_buffer[m_pos]);
            }

            if (!inNumber && c >= '0' && c <= '9' )
            {
                // Output number indicator at start of a number
                inNumber = true;
                VerifyStringLength(length);
                s[length++] = BRAILLE_CHAR_NUMBER;
            }
            else if (inNumber && encoding[c] == BRAILLE_CHAR_SPACE)
            {
                // Number ends at a space.
                // Non-number characters encountered before a space will simply be output as is.
                inNumber = false;
            }

            VerifyStringLength(length);
            s[length++] = encoding[c];
            m_pos++;
        }
    }

    m_pos++; // Go past the right quote.

    ExpectEmptyRestOfLine();

    return length;
}

// If we're at a comma, consumes it.
// Returns whether a comma was found.
bool AsmFile::ConsumeComma()
{
    if (m_buffer[m_pos] == ',')
    {
        m_pos++;
        return true;
    }

    return false;
}

// Converts digit character to numerical value.
static int ConvertDigit(char c, int radix)
{
    int digit;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'F')
        digit = 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        digit = 10 + c - 'a';
    else
        return -1;

    return (digit < radix) ? digit : -1;
}

// Reads an integer. If the integer is greater than maxValue, it returns -1.
int AsmFile::ReadPadLength()
{
    if (!IsAsciiDigit(m_buffer[m_pos]))
        RaiseError("expected integer");

    int radix = 10;

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        radix = 16;
        m_pos += 2;
    }

    unsigned n = 0;
    int digit;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;

        if (n > kMaxStringLength)
            RaiseError("pad length greater than maximum length (%d)", kMaxStringLength);

        m_pos++;
    }

    return n;
}

// Outputs the current line and moves to the next one.
void AsmFile::OutputLine()
{
    while (m_buffer[m_pos] != '\n' && m_buffer[m_pos] != 0)
        m_pos++;

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
        {
            RaiseWarning("file doesn't end with newline");
            puts(&m_buffer[m_lineStart]);
        }
        else
        {
            RaiseError("unexpected null character");
        }
    }
    else
    {
        m_buffer[m_pos] = 0;
        puts(&m_buffer[m_lineStart]);
        m_buffer[m_pos] = '\n';
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
}

// parses an assumed C `enum`. Returns false if `enum { ...` is not matched
bool AsmFile::ParseEnum()
{
    if (!m_doEnum)
        return false;

    long fallbackPosition = m_pos;
    std::string headerFilename = "";
    long currentHeaderLine = SkipWhitespaceAndEol();
    std::string enumName = ReadIdentifier();
    currentHeaderLine += SkipWhitespaceAndEol();
    std::string enumBase = "0";
    long enumCounter = 0;
    long symbolCount = 0;

    if (m_buffer[m_pos] == ':') // : <type>
    {
        m_pos++;
        std::string underlyingType;
        do {
            currentHeaderLine += SkipWhitespaceAndEol();
            underlyingType = ReadIdentifier();
        } while (!underlyingType.empty());
        currentHeaderLine += SkipWhitespaceAndEol();
    }

    if (m_buffer[m_pos] != '{') // assume assembly macro, otherwise assume enum and report errors accordingly
    {
        m_pos = fallbackPosition - 4;
        return false;
    }

    currentHeaderLine += FindLastLineNumber(headerFilename);
    m_pos++;
    for (;;)
    {
        currentHeaderLine += SkipWhitespaceAndEol();
        std::string currentIdentName = ReadIdentifier();
        if (!currentIdentName.empty())
        {
            std::printf("# %ld \"%s\"\n", currentHeaderLine, headerFilename.c_str());
            currentHeaderLine += SkipWhitespaceAndEol();
            if (m_buffer[m_pos] == '=')
            {
                m_pos++;
                SkipWhitespace();
                enumBase.clear();
                for (;;)
                {
                    if (m_pos == m_size)
                        RaiseError("unexpected EOF");
                    if (m_buffer[m_pos] == ',')
                        break;
                    if (m_buffer[m_pos] == '\n')
                    {
                        currentHeaderLine++;
                        enumBase.push_back(' ');
                    }
                    else
                    {
                        enumBase.push_back(m_buffer[m_pos]);
                    }
                    m_pos++;
                }
                enumCounter = 0;
            }
            std::printf(".equiv %s, (%s) + %ld\n", currentIdentName.c_str(), enumBase.c_str(), enumCounter);
            enumCounter++;
            symbolCount++;
        }
        else if (symbolCount == 0)
        {
            RaiseError("%s:%ld: empty enum is invalid", headerFilename.c_str(), currentHeaderLine);
        }

        if (m_buffer[m_pos] == '#')
        {
            currentHeaderLine = ParseLineSkipInEnum();
        }
        else if (m_buffer[m_pos] != ',')
        {
            currentHeaderLine += SkipWhitespaceAndEol();
            if (m_buffer[m_pos++] == '}' && m_buffer[m_pos++] == ';')
            {
                ExpectEmptyRestOfLine();
                break;
            }
            else
            {
                RaiseError("unterminated enum from included file %s:%ld", headerFilename.c_str(), currentHeaderLine);
            }
        }
        m_pos++;
    }
    return true;
}

// Asserts that the rest of the line is empty and moves to the next one.
void AsmFile::ExpectEmptyRestOfLine()
{
    SkipWhitespace();

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
            RaiseWarning("file doesn't end with newline");
        else
            RaiseError("unexpected null character");
    }
    else if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
    else if (m_buffer[m_pos] == '\r' && m_buffer[m_pos + 1] == '\n')
    {
        m_pos += 2;
        m_lineStart = m_pos;
        m_lineNum++;
    }
    else
    {
        RaiseError("junk at end of line");
    }
}

// Checks if we're at the end of the file.
bool AsmFile::IsAtEnd()
{
    return (m_pos >= m_size);
}

// Output the current location to set gas's logical file and line numbers.
void AsmFile::OutputLocation()
{
    std::printf("# %ld \"%s\"\n", m_lineNum, m_filename.c_str());
}

// Reports a diagnostic message.
void AsmFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_filename.c_str(), m_lineNum, type, buffer);
}

#define DO_REPORT(type)                   \
do                                        \
{                                         \
    std::va_list args;                    \
    va_start(args, format);               \
    ReportDiagnostic(type, format, args); \
    va_end(args);                         \
} while (0)

// Reports an error diagnostic and terminates the program.
void AsmFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void AsmFile::RaiseWarning(const char* format, ...)
{
    DO_REPORT("warning");
}

// Skips Whitespace including newlines and returns the amount of newlines skipped
int AsmFile::SkipWhitespaceAndEol()
{
    int newlines = 0;
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ' || m_buffer[m_pos] == '\r' || m_buffer[m_pos] == '\n')
    {
        if (m_buffer[m_pos] == '\n')
            newlines++;
        m_pos++;
    }
    return newlines;
}

int AsmFile::ParseLineSkipInEnum(void)
{
    m_pos++;
    while (m_buffer[m_pos] == ' ' || m_buffer[m_pos] == '\t')
        m_pos++;

     if (!IsAsciiDigit(m_buffer[m_pos]))
        RaiseError("malformatted line indicator found inside `enum`, expected line number");

    unsigned n = 0;
    int digit = 0;
    while ((digit = ConvertDigit(m_buffer[m_pos++], 10)) != -1)
        n = 10 * n + digit;

    while (m_buffer[m_pos] == ' ' || m_buffer[m_pos] == '\t')
        m_pos++;

    if (m_buffer[m_pos++] != '"')
        RaiseError("malformatted line indicator found before `enum`, expected filename");

    while (m_buffer[m_pos] != '"')
    {
        unsigned char c = m_buffer[m_pos++];

        if (c == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in line indicator");
            else
                RaiseError("unexpected null character in line indicator");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in line indicator", c);

        if (c == '\\')
        {
            c = m_buffer[m_pos];
            RaiseError("unexpected escape '\\%c' in line indicator", c);
        }
    }
    return n - 1;
}

// returns the last line indicator and its corresponding file name without modifying the token index
int AsmFile::FindLastLineNumber(std::string& filename)
{
    long pos = m_pos;
    long linebreaks = 0;
    while (m_buffer[pos] != '#' && pos >= 0)
    {
        if (m_buffer[pos] == '\n')
            linebreaks++;
        pos--;
    }

    if (pos < 0)
        RaiseError("line indicator for header file not found before `enum`");

    pos++;
    while (m_buffer[pos] == ' ' || m_buffer[pos] == '\t')
        pos++;

    if (!IsAsciiDigit(m_buffer[pos]))
        RaiseError("malformatted line indicator found before `enum`, expected line number");

    unsigned n = 0;
    int digit = 0;
    while ((digit = ConvertDigit(m_buffer[pos++], 10)) != -1)
        n = 10 * n + digit;

    while (m_buffer[pos] == ' ' || m_buffer[pos] == '\t')
        pos++;

    if (m_buffer[pos++] != '"')
        RaiseError("malformatted line indicator found before `enum`, expected filename");

    while (m_buffer[pos] != '"')
    {
        unsigned char c = m_buffer[pos++];

        if (c == 0)
        {
            if (pos >= m_size)
                RaiseError("unexpected EOF in line indicator");
            else
                RaiseError("unexpected null character in line indicator");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in line indicator", c);

        if (c == '\\')
        {
            c = m_buffer[pos];
            RaiseError("unexpected escape '\\%c' in line indicator", c);
        }

        filename += c;
    }

    return n + linebreaks - 1;
}

std::string AsmFile::ReadIdentifier()
{
    long start = m_pos;
    if (!IsIdentifierStartingChar(m_buffer[m_pos]))
        return std::string();

    m_pos++;

    while (IsIdentifierChar(m_buffer[m_pos]))
        m_pos++;

    return std::string(&m_buffer[start], m_pos - start);
}

long AsmFile::ReadInteger(std::string filename, long line)
{
    bool negate = false;
    int radix = 10;
    if (!IsAsciiDigit(m_buffer[m_pos]))
    {
        if (m_buffer[m_pos++] == '-')
            negate = true;
        else
            RaiseError("expected number in included file %s:%ld", filename.c_str(), line);
    }

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        radix = 16;
        m_pos += 2;
    }
    else if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'b')
    {
        radix = 2;
        m_pos += 2;
    }
    else if (m_buffer[m_pos] == '0' && IsAsciiDigit(m_buffer[m_pos+1]))
    {
        radix = 8;
        m_pos++;
    }

    long n = 0;
    int digit;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;
        m_pos++;
    }

    return negate ? -n : n;
}
