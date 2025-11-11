#include <stdlib.h>
#include <stdio.h>
#include "SortedLinkedList.h"


SLL_Controller SLL_NewController(void)
{
    return (SLL_Controller){.HEAD = NULL, .TAIL = NULL, .Count = 0U};
}
SLL_Element* SLL_MakeElement(int value)
{
    SLL_Element* element = ( SLL_Element* ) malloc(sizeof(SLL_Element));
    if(!element) return NULL;

    element->Value = value;
    element->NEXT = element->PREV = NULL;

    return element;
}

SLL_Element* SLL_Insert(SLL_Controller* controller, int value, int atBeginning)
{
    SLL_Element* element = SLL_MakeElement(value);
    if(!element) return NULL;

    // Case 1: List is empty
    if(controller->Count == 0U)
    {
        controller->HEAD = element;
        controller->TAIL = element;
    }
    else
    {

        // Case 2: Insertion at Head
        if(atBeginning)
        {
            element->NEXT = controller->HEAD;
            controller->HEAD->PREV = element;
            controller->HEAD = element;
        }
        // Case 3: Insertion at Tail
        else
        {
            element->PREV = controller->TAIL;
            controller->TAIL->NEXT = element;
            controller->TAIL = element;
        }
    }

    controller->Count++;
    return element;
}

void SLL_Print(const SLL_Controller* controller)
{
    SLL_Element* iterator = controller->HEAD;
    while (iterator)
    {
        printf("%d ", iterator->Value);
        iterator = iterator->NEXT;
    }
    putchar('\n');
}

