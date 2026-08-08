# LordScientist MoMo

A mobile money (MoMo) wallet application built in C++, developed as a hands-on exploration of object-oriented programming — encapsulation, composition, inheritance, and polymorphism rather than a purely academic exercise.

## What it does

A console-based wallet system supporting:

- **Register** — create a new user with a name, phone number, and PIN
- **Deposit** — add funds to an account
- **Withdraw** — remove funds, with PIN verification and balance checks
- **Send Money** — transfer funds between two registered users
- **Check Balance** — view current balance, PIN-protected
- **View Transaction History** — a full, per-user log of every deposit, withdrawal, and transfer, correctly labeled as "sent" or "received" from each user's own point of view

## What it's meant to become

- **Persistence** — saving/loading users and balances to a file, so data survives between runs
- **A Qt GUI** — replacing the console menu with a real graphical interface, built on top of the same core logic

## Concepts demonstrated

- **Encapsulation** — `Account` and `User` keep their data private, exposing only deliberate, validated methods
- **Composition ("has-a")** — a `User` owns an `Account` as a direct member, not a pointer, reflecting their identical lifecycle
- **Inheritance & polymorphism** — an abstract `Transaction` base class with `Deposit`, `Withdrawal`, and `Transfer` subclasses, each overriding a pure virtual `display()` method
- **Pointers & references** — used deliberately, not decoratively: `findUserByNumber` returns a `User*` specifically because a search can fail and needs to represent "nothing found," which a reference cannot express
- **Separation of concerns** — all `cin`/`cout` lives in `main()`; the `Account`, `User`, and `Transaction` classes contain zero I/O, so the same logic can sit under a console menu today and a GUI later without being rewritten
- **Input validation & UX resilience** — guards against non-numeric input, invalid PINs, and includes a cancel/back pattern mid-flow

## The build process

This project was built through a deliberately slow, logic-first approach: reasoning through each design decision — why composition over inheritance for `User`/`Account`, why `Transaction` needed to be abstract, why a raw pointer was the right (not just convenient) choice for a search that can fail — before writing any code, and writing every line by hand rather than working from supplied solutions.

The result is a codebase where every design decision can be explained, not just demonstrated.

## Author

Built by LordScientist.
