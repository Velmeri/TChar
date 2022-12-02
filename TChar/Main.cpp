#include "Functions.h"

#ifdef _UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif

using namespace std;

int main() {
	TCHAR str[] = { 'H', 'E', 'L', 'l', 'o', '1', ' ', '?', '2', 'П', 'р', 'И', 'в', 'Е', 'т', '\0'};
	space_to_slash_t(str);
	count_of_letters_numbers_and_other(str);

	return 0;
}