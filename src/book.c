/**
 * Order Book Implementation.
 */
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "hftlob.h"

Book*
initBook(void){
    /*
     * Create a new Book struct and return its pointer.
     */
    Book *ptr_book = malloc(sizeof(Book));
    ptr_book->bids = createRoot();
    ptr_book->asks = createRoot();
    return ptr_book;
}

void
addOrderToBook(Order* ptr_order, Book* ptr_book){
    /*
     * Add the given order to given book.
     *
     * This currently does not check for duplicate order ids!
     */
    Limit* ptr_book_side;
    ptr_book_side = getBookSide(ptr_book, order)
    Limit* ptr_existing_limit = limitExists(ptr_book_side, ptr_order->limit);

    if (ptr_existing_limit == NULL){
        initLimit(ptr_existing_limit);
        ptr_existing_limit->limitPrice = ptr_order->limit;
        addNewLimit(ptr_book_side, ptr_existing_limit)
    }
    pushOrder(ptr_existing_limit, ptr_order);
}

int
removeOrderFromBook(Order* order, Book* book){
    /*
     * Remove the given order from the given book.
     */
    Limit* ptr_book_side;
    ptr_book_side = getBookSide(ptr_book, order)
    Limit* ptr_existing_limit = limitExists(ptr_book_side, ptr_order->limit);

    if (ptr_existing_limit == NULL){
        return 0;
    }
    *Order ptr_popped_order = popOrder(ptr_existing_limit, ptr_order);
    if (ptr_popped_order == NULL){
        return 0
    }
    return 1;
}
