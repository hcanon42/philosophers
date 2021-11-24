# Philosophers
(42 subject) Create a bunch of philosophers who eat, think and sleep.

## Table of Content

* [Technologies](#technologies)
* [Description](#description)
* [Installation](#installation)
* [Usage](#usage)
* [Utility](#utility)
* [Contributing](#contributing)

## Technologies

Project is created with:
* gcc 9.3.0

## Description

The aim of this project is to create and commnunicate between different types of threads represented by philosophers.\
A number of philosophers [number of philosophers] are sitting around a round table. A fork is between each of them.\
the principle is simple, the program must do everything to ensure that philosophers do not die.\
The philosophers die if they have not eaten within [time to die] ms.\
A philosopher can only eat if both forks next to him are available.\
Philosophers always do the actions in the same order and in a loop until they die or [number of time each philosopher must eat] is reached: 
* thinking (until two forks become free)
* eating (during [time to sleep] ms)
* sleeping (during [time to sleep] ms)

If a philospher dies, the simulation ends.

## Installation

Just pull the project !

## Usage

Classic 42 Makefile:
````sh
make		#compiles everything and create woody_woodpacker binary
make clean	#removes all the .o files
make fclean	#removes all the .o files and the "woody_woodpacker" binary
make re		#cleans everything in the project and compiles everything again
````

Specific to the project:
````sh
./philo [nb of philosophers] [time to die] [time to eat] [time to sleep] [number of times each philosopher must eat (optional)] #start the simulation
````

## Utility

I learned a lot about threads during this project, especially about memory managment and types of threads.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
