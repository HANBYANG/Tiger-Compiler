/*
 * temp.h 
 *
 */

#ifndef TEMP_H
#define TEMP_H

#include "table.h"

struct Temp_temp_ {int num;};
typedef struct Temp_temp_ *Temp_temp;
Temp_temp Temp_newtemp(void);

typedef struct Temp_tempList_ *Temp_tempList;
struct Temp_tempList_ { Temp_temp head; Temp_tempList tail;};
Temp_tempList Temp_TempList(Temp_temp h, Temp_tempList t);

typedef S_symbol Temp_label;
Temp_label Temp_newlabel(void);
Temp_label Temp_namedlabel(string name);
string Temp_labelstring(Temp_label s);

typedef struct Temp_labelList_ *Temp_labelList;
struct Temp_labelList_ { Temp_label head; Temp_labelList tail;};
Temp_labelList Temp_LabelList(Temp_label h, Temp_labelList t);

typedef struct Temp_map_ *Temp_map;
struct Temp_map_ {
  TAB_table tab; 
  Temp_map under;
};
Temp_map Temp_empty(void);
Temp_map Temp_layerMap(Temp_map over, Temp_map under);
void Temp_enter(Temp_map m, Temp_temp t, string s);
string Temp_look(Temp_map m, Temp_temp t);
void Temp_dumpMap(FILE *out, Temp_map m);
Temp_map newMap(TAB_table tab, Temp_map under);
int Temp_data(Temp_temp temp);


Temp_map Temp_name(void);

bool isequalTempList(Temp_tempList, Temp_tempList);
void Temp_appendTail(Temp_temp, Temp_tempList *);
Temp_tempList except(Temp_tempList, Temp_tempList);
Temp_tempList unionn(Temp_tempList, Temp_tempList);
Temp_tempList intersect(Temp_tempList,Temp_tempList);
Temp_tempList Temp_copyList(Temp_tempList);
int lengthOfTempList(Temp_tempList tempList);
bool inTemp_tempList(Temp_temp temp, Temp_tempList list);

#endif