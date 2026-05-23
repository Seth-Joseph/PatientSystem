#pragma once

#include "Patient.h"
#include "PatientObserver.h"

class GPNotificationSystemFacade : public PatientObserver {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);

	virtual void update(Patient* p) override { sendGPNotificationForPatient(p); }
};

