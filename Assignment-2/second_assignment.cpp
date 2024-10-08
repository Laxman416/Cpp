// PHYS30762 Programming in C++
// Assignment 2

// Program to compute mean, standard deviation and standard
// error of the a set of courses. Data is read from file
#include<iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <sstream> // for stringstream
#include<iomanip>
#include <algorithm>


// Functions to compute mean, standard deviation or for other tasks
void get_user_input(std::string& data_file, 
                  char& user_input, 
                  char& user_year, 
                  std::string& input_sort,
                  std::ifstream& myfile) // Declaring file 
{
  bool file_opened = false;
  std::cout << "Enter data filename: ";
  do 
  {
    // Ask user to enter filename
    std::cout<<"Enter data filename: ";
    std::cin>>data_file;

    myfile.open(data_file); // Open the file

    // Check if file can be opened
    if (!myfile.is_open()) 
    {
        std::cerr << "Error: file could not be opened." << std::endl;
    } 
    else 
    {
        file_opened = true; // File opened successfully, exit loop
    }
  } while (!file_opened); // do while file_opened = false

  // Ask if they want Total courses or courses for a single year
  std::cout<<"Do you want to calculate the mean and standard deviations for a specific year? (y/n): "<<std::endl;
  while(!(std::cin>>user_input) || user_input != 'y' && user_input != 'n')
  {
    std::cout<<"Invalid input. Please choose either 'y' or 'n': "<<std::endl;
    std::cin.clear();  // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
  }
  if (user_input == 'y')
  {
    std::cout<<"Which year do you want to choose? (1, 2, 3, 4): "<<std::endl;
    while(!(std::cin>>user_year) || user_year != '1' && user_year != '2' && user_year != '3' && user_year != '4')
    {
      std::cout<<"Invalid input. Please choose either 'all', '1', '2', '3', '4': "<< std::endl;
      std::cin.clear();  // Clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
    }
  }

  std::cout<<"Do you want to sort the list by course name or course number? (name/number): "<<std::endl;
  while(!(std::cin>>input_sort) || input_sort != "name" && input_sort != "number")
  {
    std::cout<<"Invalid input. Please choose either 'name' or 'number': "<<std::endl;
    std::cin.clear();  // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
  }
}

void read_from_file(std::vector<float>& grade_list,
                    std::vector<int>& course_number_list, 
                    std::vector<std::string>& course_name_list,
                    std::vector<std::string>& full_course_title_list,
                    std::string& input_sort,
                    const std::string& data_file,
                    const char& user_input,
                    const char& user_year,
                    std::ifstream& myfile) // Declaring file
{
  float grade_value; 
  int course_number;
  std::string course_name;
  std::string line;


  // Gets each line in myfile
  while (getline(myfile, line)) 
  {
    std::istringstream iss(line); //istringstream contains line

    iss>>grade_value>>course_number;
    std::getline(iss >> std::ws, course_name); // read the rest of the line into course_name

    // Formats the full_course_title
    if (user_input == 'n')
    {
      std::stringstream ss;
      ss << "PHYS " << course_number << " " << course_name;
      std::string full_course_title = ss.str();

      // Adds all variables into list
      grade_list.push_back(grade_value);
      course_number_list.push_back(course_number);
      course_name_list.push_back(course_name);
      full_course_title_list.push_back(full_course_title);
    }
    else if (user_input == 'y')
    { 
      if (std::to_string(course_number).front() == user_year) 
      {
        // Formats the full_course_title
        std::stringstream course_title_stream;
        course_title_stream<<"PHYS "<<course_number<<" "<<course_name;
        std::string full_course_title = course_title_stream.str();

        // Adds all variables into list
        grade_list.push_back(grade_value);
        course_number_list.push_back(course_number);
        course_name_list.push_back(course_name);
        full_course_title_list.push_back(full_course_title);
      }
    }
  }
  myfile.close();
}

float mean_calculation(const std::vector<float>& grade_list, const int& N)   
{
  // This function calculates the mean of the grades
  // Compute mean
  if (grade_list.empty()) 
  {
    std::cerr << "Error: Grade list is empty!" << std::endl;
    return 0.0f; // Return 0 if the list is empty
  }

  float sum_mean = 0.00f;
  for (float grade : grade_list) 
  {
    sum_mean += grade;
  }
  float mean = sum_mean / N;

   
  return mean;
}

float std_calculation(const std::vector<float>& grade_list, const int& N, const float& mean)
{
  // Caluclates std of the grades
  if (grade_list.empty()) 
  {
    std::cerr << "Error: Grade list is empty!" << std::endl;
    return 0.0f; // Return 0 if the list is empty
  }
  float sum_std = 0.00f;
  for (float x : grade_list) 
  {
    sum_std += pow(x - mean, 2);
  }
  float std_dev = std::sqrt(sum_std / (N - 1));
  return std_dev;
}

bool compareByTopicTitle(const std::string& element_a, const std::string& element_b) 
{
  // uses element_a from the vector, which is a string: e.g PHYS 10180 First Year Laboratory
  // sort repeatedly calls this function until list is sorted according to this description

  // Finds position of second space
  size_t position_space_a = element_a.find(' ', element_a.find(' ') + 1);
  size_t position_space_b = element_b.find(' ', element_b.find(' ') + 1);

  // Extract course name from strings
  std::string titleA = element_a.substr(position_space_a + 1); // Extract title after the second space
  std::string titleB = element_b.substr(position_space_b + 1); // Extract title after the second space

  // Compare course names alphbetically
  return titleA < titleB;
}

// Main function

int main()
{
  // Declaring variables
  std::vector<float> grade_list;
  std::vector<int> course_number_list;
  std::vector<std::string> course_name_list;
  std::vector<std::string> full_course_title_list;
  std::string input_sort;
  char user_input;
  char user_year;
  std::string data_file;
  std::ifstream myfile; // Declaring file


  // Call functions

  get_user_input(data_file, user_input, user_year, input_sort, myfile);

  // Read files to get the grade, course number, course name for the selected courses
  read_from_file(grade_list, course_number_list, course_name_list, full_course_title_list, input_sort, data_file, user_input, user_year, myfile);
  // Find how many files are in the vector
  const int N = grade_list.size();
  // Calculate the mean
  float mean = mean_calculation(grade_list, N);
  // Calculate the std
  float std_dev = std_calculation(grade_list, N, mean);
  // Calculate the error of the mean
  float mean_error = std_dev/std::sqrt(N);


  std::cout<<"The list of courses requested are: "<<std::endl;
  if (input_sort == "name")
  {
    //std::sort(iterator at start, iterator at end, additional function to sort.)
    std::sort(full_course_title_list.begin(), full_course_title_list.end(), compareByTopicTitle); 
  }
  // Print the sorted vector
  std::cout << "Elements after sorting:" << std::endl;
  for (std::string full_course_title : full_course_title_list)
  {        
    std::cout<<full_course_title<<std::endl;
  }
  // Prints mean and std
  std::cout<<"The calculated mean for the listed course is: "<<std::setprecision(3)<<mean<<" +- "<<mean_error<<std::endl;
  std::cout<<"The calculated standard deviation for the listed course is: "<<std::setprecision(3)<<std_dev<<std::endl;
 return 0;
}
  