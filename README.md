# maratona-src

Welcome to maratona-src repository, where you can find my source code solutions to various programming marathons. The information below is about the SAET 2023 Marathon. My performance includes successful solutions, some solved without internet access, and one with internet access, as well as some unsuccessful attempts.

## Problem List

### Problems

| Problem Title       | Status | Description   |
|:-------------------:|:------:|:-------------:|
| A - Alergia         | ✔️      | Solved        |
| B - Jogo            | ❌     | Unsolved      |
| C - Vasilha         | ⚠️      | Solved w/i.a. |
| D - Drawkcabackward | ❌     | Unsolved      |
| E - Empilha         | ✔️      | Solved        |
| F - Falcon          | ✔️      | Solved        |
| G - Gafe            | ❌     | Unsolved      |
| H - Raid            | ❌     | Unsolved      |
| I - Lista           | ✔️      | Solved        |
| J - Meuzamigo       | ✔️      | Solved        |
| K - Tiras           | ❌     | Unsolved      |

### Successfully Solved Problems

| Problem Title | Solved Without Internet | Solved With Internet |
|:-------------:|:-----------------------:|:--------------------:|
| A - Alergia   | ✔️                       |                      |
| C - Vasilha   | ✔️                       | ✔️                    |
| E - Empilha   |                         |                      |
| F - Falco     | ✔️                       |                      |
| I - Lista     | ✔️                       |                      |
| J - Meuzamigo | ✔️                       |                      |

### Unsuccessful Attempts

| Problem Title           | Unsolved |
|:-----------------------:|:--------:|
| B - Jogo                | ❌       |
| D - Drawkcabackward     | ❌       |
| G - Gafe                | ❌       |
| H - Raid                | ❌       |
| K - Tiras               | ❌       |

## Description

In this repository, each problem is organized within its dedicated directory, following a structured layout. Below is an example of the directory tree for a problem:

\```
A-Alergia (e.g., saet-2023/A-Alergia)
│
├── problem                         <- Problem Statement
├── src.c (for Solved Problems)     <- Source Code Solution (C)
│
├── test                            <- Test Cases Directory
│   ├── input-1                     <- Input File 1
│   ├── output-1                    <- Expected Output for Input 1
│   ├── input2                      <- Input File 2
│   ├── output2                     <- Expected Output for Input 2
│   ├── ...                         <- Additional Test Cases
\```

- **Problem Directory:** The problem's unique directory containing all related files.
- **problem:** A file that describes the problem statement for this specific challenge.
- **src.c (for Solved Problems):** In the case of successfully solved problems, the source code solution is provided in C or C++ (mostly in C).
- **test:** A directory that holds test cases for the problem, typically with pairs of input and expected output files.

This organized structure allows for easy access to problem statements, test data, and source code solutions for each challenge. You can explore the problem directories to review problem descriptions, test your solutions, and use them with the main.sh script included in this repository.

If you have any questions or need assistance, please don't hesitate to reach out.

## Using the `main.sh` Script

Included in the root directory of this repository, you'll find a handy `main.sh` script that simplifies the process of compiling and testing your solutions against the provided test cases. This script is designed to save you time and streamline your workflow.

### Syntax

To use the `main.sh` script, follow this syntax:

\```shell
./main.sh <marathon> <problem>
\```

- `<marathon>`: Replace this with the specific marathon or contest name (e.g., saet-2023).
- `<problem>`: Replace this with the problem code or identifier (e.g., "A" for Problem A).

### Example

For instance, to compile and test the solution for Problem A (A-Alergia) of the saet-2023 marathon, you can use the following command:

\```shell
./main.sh saet-2023 A
\```

The script will automatically locate the problem directory, compile your source code solution, and test it against the provided test cases in the `test` directory.

This streamlined approach ensures that you can easily verify the correctness of your solutions and assess their performance against the test cases for each problem.

If you encounter any issues or have questions about using the `main.sh` script, please don't hesitate to reach out for assistance.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments

I would like to express my gratitude to the organizers of the programming marathons for creating challenging problems that have contributed to my growth as a programmer. I also extend my appreciation to the programming community for their support and resources that have assisted me on this journey.

Feel free to contact me if you have any questions or wish to collaborate on programming challenges solutions.

