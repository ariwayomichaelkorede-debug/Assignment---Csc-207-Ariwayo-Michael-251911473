# Assignment — COS 201 / CSC 207 Lecture

## Program 1: Odd or Even Checker (C++)

A C++ program that asks the user for an integer and reports whether it is an
**Odd** number or an **Even** number.

After every result the user gets a menu with two options:

- **1 — Check another number**: the program keeps running so the user can test
  as many numbers as they want, one after another.
- **2 — Exit**: the program prints a goodbye message and closes.

## Files

| File           | Description                          |
|----------------|--------------------------------------|
| `odd_even.cpp` | The C++ source code                  |
| `odd_even.exe` | Compiled program (Windows, 64-bit)   |
| `README.md`    | This documentation file              |

## How It Works

1. The program prints a title and prompts the user to enter a number.
2. It reads the number as an `int`.
3. It checks whether `number % 2 == 0` (the remainder after dividing by 2):
   - If the remainder is `0`, the number is **Even**.
   - Otherwise, the number is **Odd**.
4. It prints the result, then shows the options menu (1 = check another
   number, 2 = exit).
5. Choosing **1** returns to step 2; choosing **2** ends the program.

The check is done in the `isEven()` function. Input is handled by
`readNumber()` and `readChoice()`, which re-prompt the user if they type
something invalid (e.g. letters, or a number other than 1 or 2), so the
program never crashes on bad input.

## How to Compile

Using any C++ compiler (g++ example):

```
g++ -Wall -Wextra -o odd_even odd_even.cpp
```

Or with MSVC (Visual Studio Developer Command Prompt):

```
cl /nologo /EHsc /W4 /Fe:odd_even.exe odd_even.cpp
```

The included `odd_even.exe` was compiled with MSVC (Visual Studio 2022) using
`/W4` (highest warning level) and produced **zero warnings**.

## How to Run

### By double-clicking (easiest)
1. Open **File Explorer** → **Desktop** → **Michael**
2. Double-click **`odd_even.exe`**
3. A console window opens asking `Enter a number:`
4. Type a number and press **Enter** — the answer appears
5. The options menu appears:
   - Press **1** and **Enter** to check another number
   - Press **2** and **Enter** to exit (the window closes)

### From Command Prompt (cmd)
```
cd Desktop\Michael
odd_even.exe
```

### From PowerShell
PowerShell does not run programs from the current folder unless you add
`.\` in front of the name — this is normal PowerShell behaviour, not an error:
```
cd Desktop\Michael
.\odd_even.exe
```

## Example Runs

```
===== Odd or Even Checker =====

Enter a number: 10
10 is an Even number.

======== OPTIONS ========
1. Check another number
2. Exit
=========================
Enter a choice: 1

Enter a number: 7
7 is an Odd number.

======== OPTIONS ========
1. Check another number
2. Exit
=========================
Enter a choice: 2

Thank you for using the Odd or Even Checker. Goodbye!
```

Invalid inputs are handled safely:

```
Enter a number: abc
Invalid input. Please enter a whole number.
Enter a number: -13
-13 is an Odd number.

======== OPTIONS ========
1. Check another number
2. Exit
=========================
Enter a choice: 9
Invalid choice. Please enter 1 or 2.
Enter a choice: 2

Thank you for using the Odd or Even Checker. Goodbye!
```

## Test Results

All cases tested and passing:

| Input        | Expected Output                      | Actual Output | Result |
|--------------|--------------------------------------|---------------|--------|
| `10`         | Even                                 | Even          | PASS   |
| `7`          | Odd                                  | Odd           | PASS   |
| `0`          | Even                                 | Even          | PASS   |
| `-24`        | Even                                 | Even          | PASS   |
| `-13`        | Odd                                  | Odd           | PASS   |
| `15`         | Odd                                  | Odd           | PASS   |
| `abc`        | Rejects bad number, asks again       | Same          | PASS   |
| Choice `9`   | Rejects bad choice, asks again       | Same          | PASS   |
| Option `1`   | Asks for another number (keeps running) | Same       | PASS   |
| Option `2`   | Goodbye message, program closes      | Same          | PASS   |

Notes:
- **Zero is correctly treated as Even** (0 % 2 == 0).
- **Negative numbers work correctly** (e.g. -13 is Odd).
- **Invalid number input is safely rejected** and the user is asked again.
- **Invalid menu choices are safely rejected** (only 1 or 2 are accepted).
- **Option 1 loops back** so the user can keep testing numbers without
  restarting the program.
- **Option 2 exits cleanly** and the window closes.
