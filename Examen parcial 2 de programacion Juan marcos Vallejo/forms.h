#ifndef FORMS_H_INCLUDED
#define FORMS_H_INCLUDED

void form_AltA(ArrayList *pListUrg, ArrayList *pListReg, ArrayList *pListInactivosUrg, ArrayList*pListInactivosReg, int tipoDespacho);
void form_Despachar(ArrayList *pListUrgente, ArrayList *pListRegular, ArrayList *pListInacUrgentes, ArrayList *pListInacRegu);
void form_printDespachos(ArrayList *pListUrg, ArrayList *pListReg);
void form_informar(ArrayList *pListInactivosUrgentes, ArrayList *pListInactivosRegulares);
#endif // FORMS_H
