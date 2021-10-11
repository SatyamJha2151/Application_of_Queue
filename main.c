#include<stdio.h>
#include<stdlib.h>
#define max 5
int rear =-1, front = -1;
struct playlist{
    char Song_Name[50], Artist[50];
    int year, sequence;
}playlist[max];
int sequence = 1;
int isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(front==0 && rear==max-1 || front == rear+1)
        return 1;
    else
        return 0;
}
void Add_Song()
{

    if(isFull()) {
        printf("No of Song reached its limit");
        return;
    }
    if(front ==-1)
        front =0;
    if(rear == max-1)
        rear = 0;
    else
        rear++;
    playlist[rear].sequence = sequence++;
    printf("\nSong Name:\n");
    scanf("%s",playlist[rear].Song_Name);
    printf("\nEnter Artist:\n");
    scanf("%s",playlist[rear].Artist);
    printf("\nEnter Year:\n");
    scanf("%d", &playlist[rear].year);
}
void Next_Song()
{
    if(isEmpty()) {
        printf("No Song to play");
        return;
    }
    printf("Last played :\nSequence = %d\t Song name = %s\t Artist = %s\tYear = %d\n",playlist[front].sequence, playlist[front].Song_Name, playlist[front].Artist, playlist[front].year);
    if(front == rear)
    {
        front =-1;
        rear =-1;
    }
    else if(front == max-1)
        front =0;
    else
        front++;
}
void display()
{

    if(isEmpty()) {
        printf("Order list is empty to display.");
        return;
    }
    int i = front;
    if(rear>= front)
    {
        while (i<=rear)
        {
            printf("\nMusic Sequence: %d\t", playlist[i].sequence);
            printf("Song Name:%s\t", playlist[i].Song_Name);
            printf("Artist Name : %s\t", playlist[i].Artist);
            printf("Year:%d\n\n", playlist[i].year);
            i++;
        }
    }
    else
    {
        while (i<=max-1)
        {
            printf("\nMusic Sequence: %d\t", playlist[i].sequence);
            printf("Song Name:%s\t", playlist[i].Song_Name);
            printf("Artist Name : %s\t", playlist[i].Artist);
            printf("Year:%d\n\n", playlist[i].year);
            i++;
        }
        i=0;
        while (i<=rear)
        {
            printf("\nMusic Sequence: %d\t", playlist[i].sequence);
            printf("Song Name:%s\t", playlist[i].Song_Name);
            printf("Artist Name : %s\t", playlist[i].Artist);
            printf("Year:%d\n\n", playlist[i].year);
            i++;
        }

    }
}
void PLaying_song()
{
    if(isEmpty())
    {
        printf("\nNo Song to play\n");
        return;
    }
    else
    {
        printf("\nMusic Sequence: %d\t", playlist[front].sequence);
        printf("Song Name:%s\t", playlist[front].Song_Name);
        printf("Artist Name : %s\t", playlist[front].Artist);
        printf("Year:%d\n\n", playlist[front].year);
    }
}
int main()
{
    int choice;
    while(1) {

        printf("\n1. Add a Song\n2. Play Next Song\n3. Show playing Song\n4. Display Total Songs in Playlist\n");
        printf("5. Exit\nEnter your Choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Add_Song();
                break;
            case 2:
                Next_Song();
                break;
            case 3:
                PLaying_song();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
}
