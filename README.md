# ft_printf 🖨️

A custom implementation of the C standard library's `printf` function, developed as part of the 42 School curriculum. This project recreates the core functionality of printf with support for multiple format specifiers.

## 📥 Installation

```bash
git clone https://github.com/lucabarbosa/ft_printf.git
```
```bash
cd ft_printf
```

## 📋 Project Overview

The ft_printf project involves creating a variadic function that mimics the behavior of the original printf function. This implementation handles various format specifiers and returns the total number of characters printed, just like the standard printf.

## 🚀 Features

### Supported Format Specifiers

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal (base 10) number
- `%x` - Print a number in hexadecimal (base 16) lowercase format
- `%X` - Print a number in hexadecimal (base 16) uppercase format
- `%%` - Print a percent sign

### Key Features

- **Null Safety**: Handles NULL pointers and strings gracefully
- **Edge Cases**: Properly manages special values like `INT_MIN`
- **Memory Efficient**: No dynamic allocation, uses only stack memory
- **Character Counting**: Returns the exact number of characters printed

## 📁 Project Structure

```
ft_printf/
├── ft_printf.c          # Main printf function and argument conversion
├── ft_printf.h          # Header file with function prototypes
├── ft_pointerhex.c      # Pointer to hexadecimal conversion
├── ft_putchar_printf.c  # Character output function
├── ft_putnbr_hex.c      # Number to hexadecimal conversion
├── ft_putnbr_printf.c   # Integer output function
├── ft_putnbr_u.c        # Unsigned integer output function
├── ft_putstr_printf.c   # String output function
└── ft_strchr.c          # String character search function
```

## 🎨 Visual Documentation

This project includes detailed visual explanations created with Excalidraw to help understand the implementation:

### Viewing the Diagrams

To view the visual documentation:

1. **convert_to_hex.excalidraw** - Illustrates the hexadecimal conversion process
2. **explanation_func_var.excalidraw** - Explains function variables and data flow

#### How to View Excalidraw Files:

1. **Online Method**:
   - Go to [excalidraw.com](https://excalidraw.com)
   - Click "Open" or drag and drop the `.excalidraw` files
   - The diagrams will load with all the visual explanations

2. **VS Code Method**:
   - Install the "Excalidraw" extension by pomdtr
   - Open the `.excalidraw` files directly in VS Code
   - View and edit the diagrams within your editor

3. **GitHub Method**:
   - If viewing on GitHub, the raw files can be copied and pasted in excalidraw.com

The diagrams provide visual insights into:
- How hexadecimal conversion works step by step
- Function call flow and variable relationships
- Memory layout and pointer handling
- Edge case management strategies

## 🛠️ Compilation

To compile the project:

```bash
# Compile all source files
gcc -Wall -Wextra -Werror *.c -o test
```

## 📖 Usage

### Basic Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

### Example Output

```c
char c = 'A';
int num = -42;
unsigned int u_num = 42;
void *ptr = &c;

ft_printf("Character: %c\n", c);           // Character: A
ft_printf("String: %s\n", "Hello");        // String: Hello
ft_printf("Decimal: %d\n", num);           // Decimal: -42
ft_printf("Integer: %i\n", num);           // Integer: -42
ft_printf("Unsigned: %u\n", u_num);        // Unsigned: 42
ft_printf("Hex lower: %x\n", 255);         // Hex lower: ff
ft_printf("Hex upper: %X\n", 255);         // Hex upper: FF
ft_printf("Pointer: %p\n", ptr);           // Pointer: 0x7ffeefbff5bc
ft_printf("Percent: %%\n");                // Percent: %
```

## 🔧 Implementation Details

### Core Functions

- **ft_printf()**: Main function that parses format string and calls appropriate converters
- **ft_convert_args()**: Handles argument conversion based on format specifier
- **ft_pointerhex()**: Converts pointer addresses to hexadecimal with "0x" prefix
- **ft_putnbr_hex()**: Converts numbers to hexadecimal (supports both cases)
- **ft_putnbr_printf()**: Handles signed integer printing with edge cases
- **ft_putnbr_u()**: Handles unsigned integer printing

### Special Handling

- **NULL Pointers**: Displays "(nil)" for null pointers
- **NULL Strings**: Displays "(null)" for null string pointers
- **INT_MIN**: Special handling for the minimum integer value (-2147483648)
- **Zero Values**: Proper handling of zero in all numeric formats

## 🧪 Testing

The project includes comprehensive test cases in the commented main function within `ft_printf.c`. These tests compare the output and return values with the standard printf function to ensure accuracy.

## 📚 Learning Objectives

This project teaches:
- Variadic functions in C (`va_list`, `va_start`, `va_arg`, `va_end`)
- Type conversions and casting
- Recursive algorithms for number base conversions
- Memory management and pointer arithmetic
- Edge case handling in systems programming
- Modular programming and code organization

## ⚡ Performance Notes

- Uses only the `write()` system call for output
- No malloc/free - entirely stack-based
- Efficient recursive algorithms for base conversions
- Minimal function call overhead

## 🔍 42 School Standards

This implementation follows 42 School's coding standards:
- **Norm compliant**: Follows 42's coding norm
- **No forbidden functions**: Uses only allowed functions
- **Memory safety**: No memory leaks or undefined behavior
- **Error handling**: Robust handling of edge cases

---

*This project is part of the 42 School common core curriculum, focusing on low-level programming concepts and reimplementation of standard library functions.*
