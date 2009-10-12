
#ifndef PQuery_DEFINED
#define PQuery_DEFINED 1

#ifdef __cplusplus
extern "C" {
#endif

//#include "PDB.h"
#include "Datum.h"
#include "CHash.h"

//typedef struct PNode PNode;

typedef struct
{
	void *node;
	void *tmpNode;
		
	Datum *id;
	Datum *after;
	Datum *before;
	Datum *whereKey;
	Datum *whereValue;
		
	unsigned int selectCount;
	unsigned int selectCountMax;
	unsigned int hasFilter;
} PQuery;

typedef int (PQueryMethod)(PQuery *);

PQuery *PQuery_new(void);
void PQuery_free(PQuery *self);

void PQuery_setNode_(PQuery *self, void *node);
void PQuery_setTmpNode_(PQuery *self, void *node);

void PQuery_setId_(PQuery *self, Datum *d);
void PQuery_setAfter_(PQuery *self, Datum *d);
void PQuery_setBefore_(PQuery *self, Datum *d);
void PQuery_setWhereKey_(PQuery *self, Datum *d);
void PQuery_setWhereValue_(PQuery *self, Datum *d);
void PQuery_setSelectCountMax_(PQuery *self, unsigned int n);

int PQuery_setup(PQuery *self);
void PQuery_enumerate(PQuery *self);

unsigned int PQuery_selectCount(PQuery *self);

#ifdef __cplusplus
}
#endif
#endif