#pragma once

#include "AbstractPatientDatabaseLoader.h"

#include <vector>
#include <memory>

class CompositePatientLoader : public AbstractPatientDatabaseLoader
{
public:
    void addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader)
    {
        _loaders.push_back(std::move(loader));
    }

    virtual void initialiseConnection() override
    {
        for (auto& loader : _loaders)
        {
            loader->initialiseConnection();
        }
    }

    virtual void loadPatients(std::vector<Patient*>& patientIn) override
    {
        for (auto& loader : _loaders)
        {
            loader->loadPatients(patientIn);
        }
    }

    virtual void closeConnection() override
    {
        for (auto& loader : _loaders)
        {
            loader->closeConnection();
        }
    }

private:
    std::vector<std::unique_ptr<AbstractPatientDatabaseLoader>> _loaders;
};