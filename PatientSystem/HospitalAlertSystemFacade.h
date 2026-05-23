#pragma once

#include "Patient.h"
#include "PatientObserver.h"

class HospitalAlertSystemFacade : public PatientObserver
{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	virtual void update(Patient* p) override { sendAlertForPatient(p); }
	void sendAlertForPatient(Patient* p);

};

