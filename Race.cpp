#include "Race.h"

/********************
File: Race.cpp
Project: CMSC 202 Project 2, Fall 2022
Author: Hasnain Ali
Date: 10/10/22
Section: 10/15
Email: hali6@umbc.edu

This file contains code for managing the race, as well as
the main menu.
********************/

// Race
// Creates an object of type Race
Race::Race() {
}

// StartRace
// Starts a new race
void Race::StartRace() {
  bool winner = false;                                          // A boolean used to verify whether or not there's a winner in the current game
  int races = m_myPlayer.GetRaces();                            // An int that represents the number of races the player currently has
  races = races + 1;
  // Sets a new value for the number of races
  m_myPlayer.SetRaces(races);
  int trackLength = 0;                                          // The current length of the track
  int possibleWinner;                                           // An int that represents whether or not there's a winner
  // Makes sure the user enters a length from 1-100
  while ((trackLength <= 0) || (trackLength > 100)) {
    cout << "How long do you want to race for? \n";
    cin >> trackLength;
    if ((trackLength <= 0) || (trackLength > 100)) {
      cout << "Length must be between 1 and 100 \n";
    }
  }
  // Sets the track length as the user input
  m_track.SetLength(trackLength);
  // Populates the obstacles array with obstacles
  m_track.PopulateObstacles();
  // While there isn't a winner
  while (winner == false) {
    int userSelect = RaceOptions();                            // An int that represents the option the user picked while racing
    // If the user selected option 1, show them the current
    // track status
    if (userSelect == 1) {
      m_track.GetStatus();
    }
    else {
      // Else progress the race
      ProgressRace(userSelect);
    }
    // Checks to see if anyone won
    possibleWinner = m_track.CheckWin();
    if (possibleWinner != -1) {
      winner = true;
    }
    else {
      winner = false;
    }
  }
  // Once a winner is found, resets the locations of all players
  // back to 0
  m_track.ResetLocation();
  // If the user was the one who won
  if (possibleWinner == 0) {
    m_myPlayer.IncreaseWins();
    m_myPlayer.IncreaseStat();
  }
}

// GetRacerInfor
// Gets the user's name they want for their racer
void Race::GetRacerInfo() {
  string name;                                                 // A string that represents the name the user has chosen for their racer
  cout << "What is yout racer's name? \n";
  getline(cin, name);
  m_myPlayer = name;
}

// ProgressRace
// Given the user's choice, checks if they pass their obstacle
void Race::ProgressRace(int userChoice) {
  // Randomly asssigns a difficulty to all obstacles
  int obstacleDifficulty = (rand() % BASE_DIFFICULTY) + 1;     // An int that represents the difficulty of the obstacles
  // Gets the string value of the current obstacle the user
  // is on
  string currentObstacle = m_track.ConvertObstacle(0);         // A string that represents the name of the current obstacle
  // If the user enters a choice matching the obstacle type,
  // they get a bonus on their chance of passing the current
  // obstacle
  if (currentObstacle == "speed" && userChoice == 2) {
    int currentSpeed = m_myPlayer.GetSpeed();                  // An int that represents the current speed stat of the user
    int currentChance = (5 * currentSpeed) + BASE_SKILL;       // An int that represents the current chance the user has to overcome the obstacle
    cout << "You are trying to progress the race! \n";
    if (currentChance >= obstacleDifficulty) {
      cout << "You made it through the speed obstacle! \n";
      // Increments the user's location by 1
      m_track.IncrementLocation(0);
    }
    else {
      int falls = m_myPlayer.GetFalls();                       // An int that represents the number of falls
      falls = falls + 1;
      // Sets a new value for the number of falls
      m_myPlayer.SetFalls(falls);
      cout << "You fell! \n";
    }
  }
  // If the user enters a choice matching the obstacle type,
  // they get a bonus on their chance of passing the current
  // obstacle
  else if (currentObstacle == "agility" && userChoice == 3) {
    int currentAgility = m_myPlayer.GetAgility();              // An int that represents the current agility stat of the user
    int currentChance = (5 * currentAgility) + BASE_SKILL;     // An int that represents the current chance the user has to overcome the obstacle
    cout << "You are trying to progress the race! \n";
    if (currentChance >= obstacleDifficulty) {
      cout << "You made it through the agility obstacle! \n";
      // Increments the user's location by 1
      m_track.IncrementLocation(0);
    }
    else {
      int falls = m_myPlayer.GetFalls();                       // An int that represents the number of falls
      falls = falls + 1;
      // Sets a new value for the number of falls
      m_myPlayer.SetFalls(falls);
      cout << "You fell! \n";
    }
  }
  // If the user enters a choice matching the obstacle type,
  // they get a bonus on their chance of passing the current
  // obstacle
  else if (currentObstacle == "jump" && userChoice == 4) {
    int currentJump = m_myPlayer.GetJump();                   // An int that represents the current jump stat of the user
    int currentChance = (5 * currentJump) + BASE_SKILL;       // An int that represents the current chance the user has to overcome the obstacle
    cout << "You are trying to progress the race! \n";
    if (currentChance >= obstacleDifficulty) {
      cout << "You made it through the jump obstacle! \n";
      // Increments the user's location by 1
      m_track.IncrementLocation(0);
    }
    else {
      int falls = m_myPlayer.GetFalls();                      // An int that represents the number of falls
      falls = falls + 1;
      // Sets a new value for the number of falls
      m_myPlayer.SetFalls(falls);
      cout << "You fell! \n";
    }
  }
  else {
    // If the user enter's a choice that does not match the
    // obstacle type, then they don't get the bonus on their
    // chance of passing the current obstacle
    int currentChance = BASE_SKILL;                          // An int that represents the current chance the user has to overcome the obstacle
    cout << "You are trying to progress the race! \n";
    if (currentChance >= obstacleDifficulty) {
      cout << "You made it through the " << currentObstacle << " obstacle! \n";
      // Increments the user's location by 1
      m_track.IncrementLocation(0);
    }
    else {
      int falls = m_myPlayer.GetFalls();                     // An int that represents the number of falls
      falls = falls + 1;
      // Sets a new value for the number of falls
      m_myPlayer.SetFalls(falls);
      cout << "You fell! \n";
    }
  }
  ProgressComputer(obstacleDifficulty);
}

// MsinMenu
// Manages the main menu
bool Race::MainMenu() {
  int userMenuChoice;                                       // An int that represents the user's choice in the main menu
  bool validMenuChoice = false;                             // A booelan that determines whether or not the user entered a valid main menu choice
  // Asks the user what they would like to do in the main
  // menu
  while (validMenuChoice == false) {
      cout << "What would you like to do? \n";
      cout << "1. Start New Race \n";
      cout << "2. View Racer History \n";
      cout << "3. Quit \n";
      cin >> userMenuChoice;
      // If the user enters a valid choice
      if ((userMenuChoice == 3) || (userMenuChoice == 2) || (userMenuChoice == 1)) {
	validMenuChoice = true;
      }
      else {
	cout << "A valid number was not entered \n";
	validMenuChoice = false;
      }
  }
  // If the user wishes to quit
  if (userMenuChoice == 3) {
    return false;
  }
  // If the user picks 2, it shows their Racer history
  if (userMenuChoice == 2) {
    m_myPlayer.DisplayStatus();
    return true;
  }
  // If the user picks 1, it starts a race
  if (userMenuChoice == 1) {
    StartRace();
    return true;
  }
  return true;
}

// RaceOptions
// Manages the race menu
int Race::RaceOptions() {
  int userRaceChoice;                                      // An int that represents the user's choice during a race
  bool validRaceChoice = false;                            // A boolean that ensures the user entered a valid choice
  while (validRaceChoice == false) {
    cout << "What would you like to do? \n";
    cout << "1. Get Race Status \n";
    cout << "2. Try to Sprint (Speed) \n";
    cout << "3. Try to Dodge (Agility) \n";
    cout << "4. Try to Jump (Jump) \n";
    cin >> userRaceChoice;
    // If the user enters a valid number (1-3)
    if ((userRaceChoice == 1) || (userRaceChoice == 2) || (userRaceChoice == 3) || (userRaceChoice == 4)) {
      validRaceChoice = true;
    }
    else {
      cout << "A valid number was not entered \n";
      validRaceChoice = false;
    }
  }
  // Returns the int the user picked as their option
  return userRaceChoice;
}

// ManageGame
// Keeps on running the program until the user quits
void Race::ManageGame() {
  bool mainMenuChoice;                                    // A boolean that determines whether or not MainMenu() should keep on being called
  RaceTitle();
  GetRacerInfo();
  mainMenuChoice = MainMenu();
  // As long as mainMenuChoice is true, MainMenu() will
  // keep on being called
  while (mainMenuChoice == true) {
    mainMenuChoice = MainMenu();
  }
  // If mainMenuChoice isn't true, the program ends
  cout << "Thank you for playing UMBC Race! \n";
}

// ProgressComputer
// Given obstacle diffculty, checks whether or not the CPU passes their obstacle
void Race::ProgressComputer(int obstacleDifficulty) {
  // Iterates through Player1 to Player3
  for (int i = 1; i < NUM_RACERS; i++) {
    string currentObstacle = m_track.ConvertObstacle(i);                                                // A string that represents the name of the obstacle the current CPU is facing
    int currentChance = rand() % (COMP_MAX - COMP_MIN + 1) + COMP_MIN;                                  // An int that represents the current chance the CPU has of passing the obstacle
    if (currentChance >= obstacleDifficulty) {
      cout << "Player" << i << " made it through the " << currentObstacle << " obstacle! \n";
      // Increments the CPU location by one
      m_track.IncrementLocation(i);
    }
    else {
      cout << "Player" << i << " fell! \n";
    }
  }
}

// RaceTitle
// Title for race
void RaceTitle() {
}
