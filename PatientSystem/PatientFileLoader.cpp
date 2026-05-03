#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        return patients;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string uid, nameField, dateStr, diagnosis, vitalsField;

        if (!getline(ss, uid, '|') || !getline(ss, nameField, '|') || !getline(ss, dateStr, '|') || !getline(ss, diagnosis, '|'))
        {
            continue;
        }
        getline(ss, vitalsField, '|');

        stringstream nameSS(nameField);
        string lastName, firstName;
        if (!getline(nameSS, lastName, ',') || !getline(nameSS, firstName))
        {
            continue;
        }

        tm t{};
        stringstream dateSS(dateStr);
        dateSS >> get_time(&t, "%d-%m-%Y");

        Patient* p = new Patient(firstName, lastName, t);
        p->addDiagnosis(diagnosis);

        if (!vitalsField.empty())
        {
            stringstream vitalsSS(vitalsField);
            string individualVitalBlock;
            while (getline(vitalsSS, individualVitalBlock, ';'))
            {
                if (individualVitalBlock.empty()) continue;

                stringstream metricSS(individualVitalBlock);
                string btStr, bpStr, hrStr, rrStr;

                if (getline(metricSS, btStr, ',') && getline(metricSS, bpStr, ',') && getline(metricSS, hrStr, ',') && getline(metricSS, rrStr, ','))
                {
                    float bt = stof(btStr);
                    int bp = stoi(bpStr);
                    int hr = stoi(hrStr);
                    int rr = stoi(rrStr);

                    Vitals* v = new Vitals(bt, bp, hr, rr);
                    p->vitals().push_back(v);
                }
            }
        }   
        patients.push_back(p);
    }

    return patients;
}
