#include <unordered_set>
#include <vector>
using namespace std;
/*
https://leetcode.com/problems/design-phone-directory/description/

Design a phone directory that initially has maxNumbers empty slots that can store numbers. The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.

Implement the PhoneDirectory class:

PhoneDirectory(int maxNumbers) Initializes the phone directory with the number of available slots maxNumbers.
int get() Provides a number that is not assigned to anyone. Returns -1 if no number is available.
bool check(int number) Returns true if the slot number is available and false otherwise.
void release(int number) Recycles or releases the slot number.
*/
class PhoneDirectory {
public:
    unordered_set<int>hs;
    PhoneDirectory(int maxNumbers) {
        for(int i=0;i<maxNumbers;i++){
            hs.insert(i);
        }
    }
    
    int get() {
        if(hs.empty()) return -1;
        auto itr = hs.begin();
        int ans = *itr;
        hs.erase(itr);
        return ans;
    }
    
    bool check(int number) {
        return hs.find(number)!=hs.end(); // present in set
    }
    
    void release(int number) {
        hs.insert(number);
    }
};