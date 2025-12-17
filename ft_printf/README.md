# 🖨️ ft_printf

A custom implementation of the printf function from the C standard library. This project is part of the 42 school curriculum and demonstrates deep understanding of variadic functions, string formatting, and output handling in C.

---

### 📝 Note:

- This implementation follows the behavior of the standard printf function
- The project demonstrates understanding of format string parsing and type handling
- Variadic Functions: Uses **stdarg.h** to handle variable arguments
- All code follows 42 school norm requirements

---

## 📁 Files

```
ft_printf/
├── ft_printf.h
├── ft_printf.c      # Main function
├── ft_utils.c       # Utilities 
└── Makefile         # Compilation
```
This will generate **libftprintf.a**, a static library that you can link with your projects.

---

## 🔧 Features

This implementation handles the following format specifiers:

- `%c` - Character
- `%s` - String
- `%p` - Pointer address
- `%d` - Signed decimal integer
- `%i` - Signed integer
- `%u` - Unsigned decimal integer
- `%x` - Hexadecimal number (lowercase)
- `%X` - Hexadecimal number (uppercase)
- `%%` - Percent sign

---

## 👤 Author

**Victor Maia** – 42 Lisboa student

[![GitHub](https://img.shields.io/badge/GitHub-maiavictorh-181717?style=flat&logo=github&logoColor=white)](https://github.com/maiavictorh)
