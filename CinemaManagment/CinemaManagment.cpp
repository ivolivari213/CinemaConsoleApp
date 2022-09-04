/* 
*********Author**********
* Ivan Olivari
* CinemanagementApp without the e 
* Basic console APP
* This simulate a Manager/Agent cinema management 
* Feel free to modify this code I added some of comments that you uncomment to test 
* Be Creative with this code 
*/


// CinemaManagment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include<string>
using namespace std;


const char full = '+';//define for non-empty sit
const char emp = '0';//define for empty sit
const int num_rows = 15;
const int rows = 15;
const int columns = 30;
int show_menu();
void show_chart(char map[][columns]);


int main()
{
	char map[rows][columns];
	int seat = 450, seat2 = 0, quit = 1, answer, choice, row2, column2;
	double price[num_rows], cost, total = 0;
	int Seatcount[15], TotalsoldSeat = 0, tries = 0;
	string password, xtreme = "xtreme";
	bool password_validation = false;

	//if you want to access to the cinema management with a password just add this

	/*do
	{
		cout << "Please enter the password:" << '\n' << endl;
		cin >> password;

		if (password == xtreme)
		{
			password_validation = true;
		}
		else if (tries >= 3)
		{
			cout << "Access Denied" << endl;
			cout << "System Overload...Please enter any key to exit." << endl;
			cin >> password;
			exit(0);
		}
		else
		{
			cout << "Wrong password" << '\n' << endl;
			tries++;
		}

	} while (!password_validation);*/

	cout << "----------------------------------------------" << endl;
	cout << "-------WELCOME TO IVAN CINEMAS-------" << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl << endl;
	//if you want to predefine the seat price without add the price manually just predefine and delete this for loop
	for (int count = 0; count < rows; count++)
	{
		cout << "Enter the seat price" << (count + 1) << ": ";
		cin >> price[count];
	}

	// Initialize the map array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			map[i][j] = emp;
		}
	}

	do
	{
		//show menu method
		choice = show_menu();
		switch (choice)
		{
		case 1:
			cout << "Price seat";
			for (int count = 0; count < rows; count++)
			{
				cout << "Price row" << (count + 1) << ": $";
				cout << price[count] << endl;
			}
			break;

		case 2:
			cout << "View seat sales\n\n";
			for (int i = 0; i < 15; i++)
			{
				Seatcount[i] = 0;
			}

			for (int row = 0; row < 15; row++)
			{
				for (int seat = 0; seat < 30; seat++)
				{
					if (map[row][seat] == '+')
					{
						Seatcount[row]++;
					}
				}
			}

			for (int i = 0; i < 15; i++)
			{
				if (i < 9)
				{
					cout << "Seat Sold in Row0" << i + 1 << ":  " << Seatcount[i] << endl;
				}
				else
				{
					cout << "Seat Sold in Row" << i + 1 << ":  " << Seatcount[i] << endl;
				}
				TotalsoldSeat += Seatcount[i];
			}
			cout << "Total Seat Sold: " << TotalsoldSeat << endl;
			break;

		case 3:
			cout << "Avalible seats\n\n";
			show_chart(map);
			break;

		case 4:
			cout << "Buy tickets and select your seat\n";

			do
			{
				cout << "Please, select the row:";
				cin >> row2;
				cout << "Please, select your seat: ";
				cin >> column2;

				if (map[row2 - 1][column2 - 1] == '+')
				{
					cout << "Sorry that seat is sold-out, please select a new seat.";
					cout << endl;
				}
				else
				{
					cost = price[row2 - 1];
					total = total + cost;
					cout << "the cost of ticket is:" << cost << endl;
					cout << "Confirm your purchase?Enter(1=yes/2=no)";
					cin >> answer;
					seat = seat - answer;
					seat2 += answer;

					if (answer == 1)
					{
						cout << "Your purchased are proceed," << endl;
						map[row2 - 1][column2 - 1] = full;
					}
					else if (answer == 2)
					{
						cout << "Do you want to buy a another ticket?(1=yes/2=no)";
						cout << endl;
						cin >> quit;
					}
					else
					{
						cout << "Do you want to buy a another ticket?(1=si/2=no)";
						cin >> quit;
					}
				}
			} while (quit != 1);
			break;

		case 5:

			cout << "Sell tickets and select your seat\n";

			do
			{
				cout << "Please, select the row:";
				cin >> row2;
				cout << "Please, select your seat: ";
				cin >> column2;

				if (map[row2 - 1][column2 - 1] == '0')
				{
					cout << "Sorry that seat is sold-out, please select a new seat.";
					cout << endl;

				}
				else
				{
					cost = price[row2 - 1];
					total = total + cost;
					cout << "the cost of ticket is:" << cost << endl;
					cout << "Confirm your sell?Enter(1=yes/2=no)";
					cin >> answer;
					seat = seat - answer;
					seat2 += answer;

					if (answer == 1)
					{
						cout << "Your sell are proceed," << endl;
						map[row2 - 1][column2 - 1] = emp;
					}
					else if (answer == 2)
					{
						cout << "Do you want to sell a another ticket?(1=yes/2=no)";
						cout << endl;
						cin >> quit;
					}
					else
					{
						cout << "Do you want to sell a another ticket?(1=si/2=no)";
						cin >> quit;
					}
				}
			} while (quit != 1);
			break;

		case 6:
			cout << "Move seat\n\n";
			int seatedRow, seatedSeat;
			int destinationRow, destinationSeat;

			cout << "Actual Seated Row:    ";
			cin >> seatedRow;
			cout << "Actual Seated Seat:   ";
			cin >> seatedSeat;

			if (seatedRow < 1 || seatedRow>15)
			{
				cout << "Row not avaible." << endl;
				break;
			}
			else if (seatedSeat < 1 || seatedSeat>30)
			{
				cout << "Seat not avaible.";
				break;
			}

			cout << "Destination Seated Row:    ";
			cin >> destinationRow;
			cout << "Destination Seated Seat:   ";
			cin >> destinationSeat;

			if (destinationRow < 1 || destinationRow>15)
			{
				cout << "Row not avaible." << endl;
				break;
			}
			else if (destinationSeat < 1 || destinationSeat>30)
			{
				cout << "Seat not avaible.";
				break;
			}

			if (map[seatedRow - 1][seatedSeat - 1] == '+')
			{
				map[seatedRow - 1][seatedSeat - 1] = '0';
			}
			else
			{
				cout << "Not avaible" << endl;
			}

			if (map[destinationRow - 1][destinationSeat - 1] == '0')
			{
				map[destinationRow - 1][destinationSeat - 1] = '+';
			}
			else
			{
				cout << "Not avaible" << endl;
			}
			break;

		case 7:
			cout << "Purchase seat(multiple) \n\n";
			int seatRow, seatNumber, lastSeatNumber;
			cout << "Enter Seat Row: ";
			cin >> seatRow;
			cout << "Enter the seat number: ";
			cin >> seatNumber;
			cout << "Enter the last seat number: ";
			cin >> lastSeatNumber;

			if (seatRow < 1 || seatRow >15)
			{
				cout << "Seat Row not avaible." << endl;

			}
			else if (seatNumber < 1 || seatNumber>30)
			{
				cout << "Seat Number not avaible" << endl;

			}
			else if (lastSeatNumber < 1 || lastSeatNumber>30)
			{
				cout << "Last Seat Number is not avaible.";
			}
			for (int i = (seatNumber - 1); i < lastSeatNumber; i++)
			{
				map[seatRow - 1][i] = '+';
			}

			break;

		case 8:
			int SeatRow, SeatNumber, LastSeatNumber;
			cout << "Sell Seats(multiple). \n\n";
			cout << "Enter Seat Row: ";
			cin >> SeatRow;
			cout << "Enter the seat number: ";
			cin >> SeatNumber;
			cout << "Enter the last seat number: ";
			cin >> LastSeatNumber;

			if (SeatRow < 1 || SeatRow >15)
			{
				cout << "Seat Row not avaible." << endl;
			}
			else if (SeatNumber < 1 || SeatNumber>30)
			{
				cout << "Seat Number not avaible" << endl;
			}
			else if (LastSeatNumber < 1 || LastSeatNumber>15)
			{
				cout << "Last Seat Number is not avaible.";
			}
			for (int i = (SeatNumber - 1); i < LastSeatNumber; i++)
			{
				map[SeatRow - 1][i] = '0';
			}
			break;

		case 9:
			int InitialSeatRow, InitStartSeatNumber, InitLastSeatNumber;
			int DestinationSeatRow, DestStartSeatNumber, DestLastSeatNumber;
			cout << "Move Seats(multiple). \n\n";
			cout << "Actual Row: ";
			cin >> InitialSeatRow;
			cout << "Enter Start Seat Number: ";
			cin >> InitStartSeatNumber;
			cout << "Enter the Last Seat Number: ";
			cin >> InitLastSeatNumber;

			if (InitialSeatRow < 1 || InitialSeatRow>15)
			{
				cout << "Seat Row not avaible" << endl;

			}
			else if (InitStartSeatNumber < 1 || InitStartSeatNumber>30)
			{
				cout << "Start Seat number not avaible" << endl;
			}
			else if (InitLastSeatNumber < 1 || InitLastSeatNumber>30)
			{
				cout << "Last Seat Number not avaible." << endl;
			}

			for (int i = (InitStartSeatNumber - 1); i < InitLastSeatNumber; i++)
			{
				map[InitialSeatRow - 1][i] = '0';

			}

			cout << "Enter the Destination Row: ";
			cin >> DestinationSeatRow;
			cout << "Enter the Destination Start Seat Number: ";
			cin >> DestStartSeatNumber;
			cout << "Enter the Destination Last Seat Number: ";
			cin >> DestLastSeatNumber;

			if (DestinationSeatRow < 1 || DestinationSeatRow>15)
			{
				cout << "The Destination Seat Row not avaible" << endl;
			}
			else if (DestStartSeatNumber < 1 || DestStartSeatNumber>30)
			{
				cout << "The Destination Start Seat number not avaible" << endl;
			}
			else if (DestLastSeatNumber < 1 || DestLastSeatNumber>30)
			{
				cout << "The Destination Last Seat Number not avaible." << endl;
			}

			for (int i = (DestStartSeatNumber - 1); i < DestLastSeatNumber; i++)
			{
				map[DestinationSeatRow - 1][i] = '+';
			}
			break;

		case 0:
			cout << "Gracias, por usar nuestro sistema online, pase buen dia!\n\n";
			exit(0);
			break;

		default:
			cout << "ERROR,\n";
			break;

		}

	} while (choice != 0);

	return 0;
	
	
}


int show_menu()
{
	int menuchoice;
	cout << endl << endl;
	cout << "Main Menu.\n";
	cout << "1. View Seat Price.\n";
	cout << "2. View Avaible Seats.\n";
	cout << "3. View seat layout.\n";
	cout << "4. Purchase seat(single).\n";
	cout << "5. Sell seat(single).\n";
	cout << "6. Move Seat(single).\n";
	cout << "7. Purchase seat(multiple).\n";
	cout << "8. Sell Seats(multiple).\n";
	cout << "9. Move Seats(multiple).\n";
	cout << "0. Exit\n";
	cout << "***************************************\n\n";
	cout << "Please enter your choice: ";
	cin >> menuchoice;
	cout << endl << endl;
	return menuchoice;

}


void show_chart(char map[][columns])
{
	cout << "Seats" << endl;
	cout << "     01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30\n";

	for (int count = 0; count < 15; count++)
	{
		if (count < 9)
		{
			cout << endl << "R0" << (count + 1);
		}
		else
		{
			cout << endl << "R" << (count + 1);
		}

		for (int count2 = 0; count2 < 30; count2++)
		{
			cout << "   " << map[count][count2];
		}
		cout << endl;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
