# :notebook: My_C_Project
This repository is the base of all my **C** projects at ***Epitech***

## Content

### 4 folders
- **include**: Contains all my header files.
- **lib**: Contains all my library.
  - basic_c :arrow_right: Basic C functions (string/int manipulation)
  - my_printf :arrow_right: My Epitech project (it is not perfect, far from it ^^)
  - utilsCSFML :arrow_right: Useful structs and functions to make your life easier with *CSFML* library
- **source**: Contains some file code and a main.c
- **tests**: Contains two folders and a Makefile that execute some coverage code with the lib *Criterion*

### 1 Makefile
It is composed of **6 rules**
- *all*: It calls $(NAME) rule
- *$(NAME)*: It compiles and links all my libraries and all my source code to create a binary
- *tests_run*: It calls the Makefile in tests which execute unit tests
- *clean*: It removes all object files
- *fclean*: It calls clean rule and execute the script mr_clean
- *re*: It calls fclean and all rules

### 1 script
**mr_clean**: It cleans every temporary files in the directory and in it sub-directories

## Usage
If you want to use this repo for your project, you have several steps to do:
- Clone this repository on your computer with
  - https: ```git clone https://github.com/VincentFaivre/My_Project.git```
  - ssh: ```git clone git@github.com:VincentFaivre/My_Project.git```
- Add or remove some file to compile (sources and headers)
- Add or remove libraries to compile
- Change the variable $(NAME) in the root Makefile
- Change my_project.h name with your project name
- Update all the headers files accordingly with your previous changes
- Update $(UTDIR) accordingly with your previous changes

> :heavy_exclamation_mark: Some functions/files might not be eligible by the Epitech Coding Style. I do my best to fix them
