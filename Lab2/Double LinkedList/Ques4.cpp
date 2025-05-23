#include "DataLog.h"
DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList.push_back(0); // Add the first state with value 0
    currentState = logList.begin(); // Set current state to the first state
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList.push_back(data); // Add the first state with provided data
    currentState = logList.begin(); // Set current state to the first state
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
     *currentState += number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
     *currentState -= number; // Decrease the value of current state
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
    logList.erase(next(currentState), logList.end()); // Remove all states after the current one
    logList.push_back(*currentState); // Add the current state value
    currentState = prev(logList.end()); // Move iterator to the new state
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
     if (currentState != logList.begin()) {
        currentState--; // Move back to the previous state
    }
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
     if (next(currentState) != logList.end()) {
        currentState++; // Move forward to the next state
    }
}