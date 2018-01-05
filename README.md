# Lessons

1. [Array of Strings in C](https://stackoverflow.com/questions/1088622/how-do-i-create-an-array-of-strings-in-c). Either you malloc the precise amount of space (or you waste space) or you initialize a pointer array in one line which is pretty much immutable. Lesson: don't do strings in C :( .

2. [String input in C:](http://www.dummies.com/programming/c/how-to-use-the-fgets-function-for-text-input-in-c-programming/) It's much preferrable to use fgets over scanf to get strings. Format for fgets: `fgets(name of variable, max size, name of input method(->stdin) );`

3. [Modifying strings in C:](https://stackoverflow.com/questions/1011455/is-it-possible-to-modify-a-string-of-char-in-c) Initialize strings as `char a[]` instead of `char *a` if you want to modify the contents of the string.
