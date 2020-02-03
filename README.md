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
