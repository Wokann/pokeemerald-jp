#include "global.h"
#include "easy_chat.h"

extern struct EasyChatScreen *sEasyChatScreen;

static u8 GetDisplayedPersonType(void)
{
    return sEasyChatScreen->displayedPersonType;
}

extern int FooterHasFourOptions(void);

static int FooterHasFourOptions_(void)
{
    return FooterHasFourOptions();
}
