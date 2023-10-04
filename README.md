
# AggieWorks Take-Home Assignment Setup

## Introduction

This repository is a submission for the Software Engineer Take-Home assignment. The project is a full-stack application that meets the criteria outlined in the assignment instructions. Below are the steps to set up and run the program.

## Requirements

-   Ensure you have a C++ compiler installed.
-   Install Crow, a micro web framework for C++.

## Crow Setup

Follow the setup instructions provided in the [Crow documentation](https://crowcpp.org/master/getting_started/setup) to install and set up Crow on your machine.

## Repository Setup

1.  **Clone the Repository**
    

    
    `git clone https://github.com/ashw24/AggieWorks-Take-Home.git` 
    
2.  **Navigate to the Repository Directory**
    

    
    `cd AggieWorks-Take-Home` 
    
3.  **Compile the Main Program**
    

    
    `g++ -o output "Six Degrees of Kevin Bacon/main.cpp" -I include -pthread -lboost_system` 
    
4.  **Run the Program**
    

    
    `./output` 
    
5.  Once the program is running, you can interact with the frontend, which will pull data from the backend. The frontend sends data to the backend based on user interactions.
    

## Project Structure

The main program logic is located in `Six Degrees of Kevin Bacon/main.cpp`. The Crow framework is utilized for the backend, with header files located in the `include` directory.

## Criteria Met

-   **Frontend and Backend Interaction**: The frontend pulls data from the backend, allows user interactions, and sends data back to the backend.
-   **Modularity**: The codebase uses modular React components for reusable page elements and well-defined API routes.
-   **Styling**: The page is styled with a neat layout, icons, and colors.
-   **Readability**: The code is organized, clean, and readable.

## Bonus Points Achieved

-   **Error Handling**: The backend has implemented error handling and logging.
-   **TypeScript**: The frontend and backend are written in TypeScript.

## Conclusion

This project meets the requirements and criteria outlined in the Software Engineer Take-Home assignment. The README provides clear instructions on how to set up and run the program, ensuring a smooth experience for users and reviewers. You can find a demo [here]([https://youtu.be/RuX07oH7494](https://youtu.be/7hsL7PqMFSY)https://youtu.be/7hsL7PqMFSY).

