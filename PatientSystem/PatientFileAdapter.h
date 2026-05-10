#pragma once

#include "PatientFileLoader.h"
#include "AbstractPatientDatabaseLoader.h"
#include <memory>

class PatientFileAdapter : public AbstractPatientDatabaseLoader
{
public:
    PatientFileAdapter(const std::string& filename) : _filename(filename), _fileLoader(std::make_unique<PatientFileLoader>()) {}

    virtual void initialiseConnection() override {}
    virtual void loadPatients(std::vector<Patient*>& patientIn) override {
        std::vector<Patient*> loaded = _fileLoader->loadPatientFile(_filename);
        for (Patient* p : loaded)
        {
            patientIn.push_back(p);
        }
    }
    virtual void closeConnection() override {}

private:
    std::string _filename;
    std::unique_ptr<PatientFileLoader> _fileLoader;
};