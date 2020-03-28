# ft_printf
Printf Reimplementation - 42 São Paulo

At 42 Schools around the world, one of the first projects available is the reimplementation of the notorious printf function included in libc. This implementation cover the following set of flags, length modifiers and conversions, besides the availability of the width and precision modifiers.

### Flags

| Flag  | Description														 |
|-------|--------------------------------------------------------------------|
| **-** | Align replaced text to the left when enough width is given         |
| **0** | Add '0' as a padding character in numeric conversions              |
| **+** | Add a plus sign ('+') in the front of positive numeric conversions |
| **#** | Alternate input method for placeholder                             |

### Conversions

| Conversion | Description					|
|------------|------------------------------|
| **c**		 | int converted to ASCII char	|
| **s**		 | NULL - terminated string		|
| **p**		 | Pointer memory address		|
| **d**		 | int in decimal base			|
| **i**		 | int in decimal base			|
| **x**		 | int in hex base (lowercase)	|
| **X**		 | int in hex base (uppercase)	|
| **%**		 | '%' char literal				|

## Beware 42 students!
I'd not recommend to get your `libft` as a submodule, as it seems that Moulinette doesn't update the submodules during evaluation. For the submission, copy and paste your `libft` repository directly under your project repository.

## Getting Started
The static library `libftprintf.a` is ready to use after compilation. Pay attention to the requirement of `libft.a`, so any dependencies are fetched right away. The following script may be suitable to build on any macOS or Linux system.

	git clone git@github.com:AdrianWR/ft_printf.git --recurse-submodules

## Linking to your project
If, by some obscureous reason you must use an alternative to libc's printf function, you may use this library by running the following script:

	git submodule add git@github.com:AdrianWR/ft_printf.git
	git submodule update --init --recursive

Link the library to your project with the following compilation flags:

	-I.<path/to/ft_printf_repository/include> -L.<path/to/ft_printf_repository> -lftprintf
