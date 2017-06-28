/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    empleado program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    empleado program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with empleado program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;


int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(ArrayList* lista);
Employee* employee_new(void);
void employee_delete(Employee* empleado);
int employee_setId(Employee* empleado, int id);
int employee_getId(Employee* empleado);
#endif // _EMPLOYEE_H



