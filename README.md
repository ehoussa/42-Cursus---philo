# Philo Project

The Philo project at 42 Network involves solving the dining philosophers problem using threads and synchronization techniques in C.

## Table of Contents

- [Project Overview](#project-overview)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Problem Description](#problem-description)
- [Solution Approach](#solution-approach)
- [Example Usage](#example-usage)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

The main goal of the project is to simulate the dining philosophers problem, where a number of philosophers sit around a dining table with a bowl of spaghetti. They must alternate between thinking and eating, using forks placed between them. The challenge is to avoid deadlock and ensure that no philosopher starves while waiting for resources.

## Project Structure

The project typically consists of the following files:

- **philo.c**: Contains the main logic for initializing philosophers, forks, and simulating their actions.
- **utils.c**: Utility functions for time management, thread creation, and synchronization.
- **philo.h**: Header file containing function prototypes and necessary macros.
- **Makefile**: Defines compilation rules and dependencies for building the `philo` executable.

## Usage

To compile and run the `philo` program, follow these steps:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/ehoussa/42-Cursus---philo/
   cd 42-Cursus---philo


2. **Compile the program:

   ```bash
   make

This will compile the philo program and create an executable file called philo.

3. **Run the program with arguments:

   ```bash
   ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

Replace number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, and optionally number_of_times_each_philosopher_must_eat with your desired values.

# Problem Description

The dining philosophers problem is a classic synchronization problem where multiple philosophers sit around a dining table with a bowl of spaghetti. Each philosopher alternates between thinking and eating. To eat, a philosopher needs two forks, one on the left and one on the right. The challenge is to avoid deadlock and starvation while ensuring that all philosophers get a fair share of eating time.

# Solution Approach

The solution typically involves using threads for each philosopher and mutexes (or semaphores) to control access to forks. Here are key aspects of the solution:

    Thread Creation: Create a separate thread for each philosopher.
    Mutex Locks: Use mutex locks to ensure mutual exclusion when a philosopher tries to pick up or put down forks.
    Sleeping and Eating: Implement logic to handle sleeping, eating, and thinking phases for each philosopher.
    Monitoring: Monitor each philosopher to ensure they do not starve and respect the specified constraints.

# Example Usage

Assume you want to run the philo program with 5 philosophers, each with a time to die of 800 ms, time to eat of 200 ms, and time to sleep of 300 ms:

   ./philo 5 800 200 300


This will simulate the dining philosophers problem with 5 philosophers, demonstrating their actions and interactions around the dining table.
Contributing

Contributions are welcome! Please follow these steps to contribute:

    Fork the repository
    Create a new branch (git checkout -b feature/YourFeature)
    Commit your changes (git commit -am 'Add new feature')
    Push to the branch (git push origin feature/YourFeature)
    Create a new Pull Request

License

This project is licensed under the MIT License. See the LICENSE file for details.


This README template provides a structured overview of the "philo" project, including its purpose, structure, usage instructions, problem description, solution approach, example usage, contribution guidelines, and licensing information. It is formatted to be easily readable and navigable on platforms like GitHub.
