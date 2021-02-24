#include "./includes/ft_printf.h"
#include "./libft/libft.h"

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	int result_f;
	int result_r;
	char *str = "123";

	ft_printf("f = [%20p]\n", str);
	   printf("r = [%20p]\n", str);
	ft_printf("f = [%-20p]\n", str);
	   printf("r = [%-20p]\n", str);
	ft_printf("f = [%-20p]\n", (void *)0);
	   printf("r = [%-20p]\n", (void *)0);
	result_f = ft_printf("f = [%-20s]\n", (void *)0);
	result_r =    printf("r = [%-20s]\n", (void *)0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%c]\n", '\0');
	result_r =    printf("r = [%c]\n", '\0');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%.3s]\n", "hello");
	result_r =    printf("r = [%.3s]\n", "hello");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%7.5s]\n", "bombastic");
	result_r =    printf("r = [%7.5s]\n", "bombastic");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%7.5u]\n", 123);
	result_r =    printf("r = [%7.5u]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%#10.5x]\n", 123);
	result_r =    printf("r = [%#10.5x]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% d]\n", 123);
	result_r =    printf("r = [% d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+d]\n", 123);
	result_r =    printf("r = [%+d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 10.5d]\n", 123);
	result_r =    printf("r = [% 10.5d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+10.5d]\n", 123);
	result_r =    printf("r = [%+10.5d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%d]\n", -1);
	result_r =    printf("r = [%d]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+d]\n", -123);
	result_r =    printf("r = [%+d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 10.5d]\n", -123);
	result_r =    printf("r = [% 10.5d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+10.5d]\n", -123);
	result_r =    printf("r = [%+10.5d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%d]\n", -1);
	result_r =    printf("r = [%d]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+d]\n", -123);
	result_r =    printf("r = [%+d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 10d]\n", -123);
	result_r =    printf("r = [% 10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+10d]\n", -123);
	result_r =    printf("r = [%+10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%0d]\n", -1);
	result_r =    printf("r = [%0d]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%0+d]\n", -123);
	result_r =    printf("r = [%0+d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%0 10d]\n", -123);
	result_r =    printf("r = [%0 10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%0+10d]\n", -123);
	result_r =    printf("r = [%0+10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%e]\n", -123.456);
	result_r =    printf("r = [%e]\n", -123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%e]\n", 123.456);
	result_r =    printf("r = [%e]\n", 123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 30.15e]\n", 123.456);
	result_r =    printf("r = [% 30.15e]\n", 123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%030.15e]\n", 123.456);
	result_r =    printf("r = [%030.15e]\n", 123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);


	result_f = ft_printf("f = [%e]\n", -123.45678901234);
	result_r =    printf("r = [%e]\n", -123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_f = ft_printf("f = [%e]\n", 123.45678901234);
	result_r =    printf("r = [%e]\n", 123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_f = ft_printf("f = [% 30.15e]\n", 123.45678901234);
	result_r =    printf("r = [% 30.15e]\n", 123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_f = ft_printf("f = [%030.15e]\n", 123.45678901234);
	result_r =    printf("r = [%030.15e]\n", 123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);





	setlocale(LC_ALL, "");
	wchar_t msg[] = L"안녕하세요.";
	printf("%d\n", printf("%lc\n", msg[0]));
	printf("%d\n", printf("%ls\n", msg));
	ft_printf("%d\n", ft_printf("%lc\n", msg[0]));
	ft_printf("%d\n", ft_printf("%ls\n", msg));

	result_r =    printf("r = [%10lc]\n", L'\0');
	result_f = ft_printf("f = [%10lc]\n", L'\0');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_r =    printf("r = [%10lc]\n", L"안녕하세요."[1]);
	result_f = ft_printf("f = [%10lc]\n", L"안녕하세요."[1]);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("r = [%-30lc]\n", L"안녕하세요."[1]);
	result_f = ft_printf("f = [%-30lc]\n", L"안녕하세요."[1]);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("r = [%ls]\n", L"안녕하세요.");
	result_f = ft_printf("f = [%ls]\n", L"안녕하세요.");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("r = [%-30ls]\n", L"안녕하세요.");
	result_f = ft_printf("f = [%-30ls]\n", L"안녕하세요.");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);


	printf("aaaaaaaaaaaaaaaaaaaaa\n\n");
	ft_printf("%10p\n", "ptr");
	printf("%10p\n", "ptr");
	printf("aaaaaaaaaaaaaaaaaaaaa\n\n");
	ft_printf("%*.p\n", -15, "ptr");
	printf("%*.p\n", -15, "ptr");
	printf("aaaaaaaaaaaaaaaaaaaaa\n\n");
	ft_printf("%.p\n", NULL);
	printf("%.p\n", NULL);





	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");
	return 0;
}

