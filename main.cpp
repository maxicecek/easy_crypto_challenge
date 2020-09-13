#include <windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>

auto main(int arg_count, char** arg_array) -> int
{
	// set random seed to local time
	srand(time(0));

	// create string that is going to be crypted
	std::string clean_message = "here goes your secret message";

	// set shift number
	auto shift = rand() % 1024;

	// create stringstream
	std::stringstream stream{};

	// loop through clean message
	for (auto i = 0; i < clean_message.length(); i++)
	{
		// check if current char is space
		if (clean_message[i] == ' ')
		{
			// add space to the stream
			stream << " (space)";
		}
		else
		{
			// add the ('char_num' + shift) int to the stream
			stream << " " << (int)(clean_message[i] + shift);
		}
	}

	// create crypted string and assign the stream output
	auto crypted_message = stream.str();

	// print once
	std::cout << "hidden message:" << crypted_message << "\n\nyour guess: ";

	// input variable
	std::string input{};

	// while input and while input is not clean message
	while (std::getline(std::cin, input) && input != clean_message)
	{
		// wrong input
		std::cout << "\nwrong, try again: ";
	}

	// show win messagebox
	MessageBoxA(0, "good job!", "win", MB_OK | MB_ICONEXCLAMATION);

	// end
	return 0;
}
