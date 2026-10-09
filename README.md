# LeetCode Solutions Portfolio

A C-based practice portfolio organized by topic for the Activity 4 LeetCode assignment. These are starter examples for learning; run them, understand them, and submit to LeetCode yourself. No submission is marked Accepted unless you verify it on your account.

## Repository structure

- `arrays-strings/` — Two Sum and Valid Palindrome
- `basic-algorithms/` — Binary Search and Fibonacci Number
- `stacks/` — Valid Parentheses and Min Stack
- `linked-lists/` — Reverse Linked List and Merge Two Sorted Lists
- `docs/authentication.md` — authentication components, general request flow, credentials, and token safety
- `PROGRESS.md` — tracker for local tests, submissions, and screenshots

## Compile and run

With GCC installed, open a terminal in the repository and compile one file at a time. For example:

```sh
gcc arrays-strings/two_sum.c -o two_sum
./two_sum
```

On Windows PowerShell, run the output as `./two_sum.exe` (or ` .\\two_sum.exe` depending on your shell). Repeat with the relevant source file and output name for each example. The C files include small `main` functions for local demonstrations; adapt the algorithm to the function signature expected by each LeetCode problem before submitting.

## How to finish the assignment

1. Compile and test each solution locally.
2. Add a short Markdown explanation for each problem, including the approach, complexity, and test cases.
3. Submit the solution on LeetCode and record the actual result in `PROGRESS.md`.
4. Capture an Accepted screenshot from your own submission if required by the handout.
5. Commit and push your updates.

## Authentication scope

This repository is a LeetCode practice portfolio, not an authentication service. `docs/authentication.md` explains general sign-in concepts and GitHub Git authentication. It does not claim that this repository implements LeetCode login, issues tokens, or validates API requests.

## Safety

Never commit passwords, session cookies, personal access tokens, API keys, SSH private keys, or `.env` files. Use official sign-in flows and keep development secrets outside source control.
