// Last updated: 8/30/2025, 8:17:56 PM
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int starting_energy = accumulate(energy.begin(), energy.end(), 0);
        //cout << starting_energy << " ";
        int training_hours = starting_energy - initialEnergy;
        if(training_hours < 0)
            training_hours = 0;
        else
            training_hours++;
        //cout << training_hours << " " << endl;
        
        int training_exp = 0;
        int exp = initialExperience;
        for(int i = 0; i < experience.size(); i++){
            if(exp <= experience[i]){
                training_exp += (experience[i] - exp + 1);
                exp += (experience[i] - exp + 1 + experience[i]);
            }else{
                exp += experience[i];
            }
        }
        training_hours += training_exp;
        return training_hours;
    }
};

/*
        int improvement = 0;
        int exp = initialExperience;
        for(int i = 0; i < experience.size(); i++){
            if(exp < experience[i]){
                improvement += (experience[i] - exp + 1);
            }else if(exp == experience[i]){
                improvement++;
            }
            exp = improvement + exp + experience[i];
        }
        if(improvement > 0)
            training_hours += (improvement);
        cout << improvement;
*/