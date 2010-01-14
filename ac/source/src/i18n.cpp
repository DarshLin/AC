// internationalization and localization

#include "cube.h"
#include <locale.h>

i18nmanager::i18nmanager(const char *domain, const char *basepath) : domain(domain), basepath(basepath)
{
	locale = setlocale(LC_ALL, ""); // use current default locale
	bindtextdomain(domain, basepath); // set base path
	textdomain(domain);
	bind_textdomain_codeset(domain, "UTF-8"); // we use the utf-8 charset only

	printf("current locale: %s\n", locale);

	const char *test = _("About");
	std::string test2(test);
	bool valid = utf8::is_valid(test2.begin(), test2.end());

	printf("is valid: %s", valid ? "true" : "false");
}

// export gettext to cubescript
void script_gettext(char *msgid)
{
	const char *translated = _gettext(msgid);
	result(translated);
}

COMMANDN(gettext, script_gettext, ARG_1STR);
