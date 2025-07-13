#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char email[100];
    char phone[15];
} UserData;

typedef struct {
    int vaccine[4][4][4];
    int appointment[13][32][50][4];
} HospitalData;


void loadUserData(UserData *userData) {
    printf("Enter your name: ");
    fgets(userData->name, sizeof(userData->name), stdin);

    printf("Enter your email: ");
    fgets(userData->email, sizeof(userData->email), stdin);

    printf("Enter your phone number: ");
    fgets(userData->phone, sizeof(userData->phone), stdin);
}
void loadHospitalData(HospitalData *hospitalData) {
    FILE *file = fopen("hospital_data.txt", "r");
    int i,j,k,l;
    if (file==NULL){
        perror("Error opening file");
        return;
    }
    for (i=0;i<4;++i){
        for (j=0;j<4;++j){
            for (k=0;k<4;++k){
                fscanf(file, "%d", &hospitalData->vaccine[i][j][k]);
            }
        }
    }
    for (i=0;i<13;++i){
        for (j=0;j<32;++j){
            for (k=0;k<50;++k){
                for (l=0;l<4;++l){
                    fscanf(file, "%d", &hospitalData->appointment[i][j][k][l]);
                }
            }
        }
    }
    fclose(file);
}
void saveUserData(const UserData *userData) {
    FILE *file = fopen("Userdata.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Name: %s\n", userData->name);
    fprintf(file, "Email: %s\n", userData->email);
    fprintf(file, "Phone: %s\n", userData->phone);

    fclose(file);
}
void saveHospitalData(const HospitalData *hospitalData) {
    FILE *file = fopen("hospital_data.txt", "w");
    int i,j,k,l;
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (i=0;i<4;++i){
        for (j=0;j<4;++j){
            for (k=0;k<4;++k) {
                fprintf(file, "%d ", hospitalData->vaccine[i][j][k]);
            }
        }
    }
    for (i=0;i<13;++i){
        for (j=0;j<32;++j){
            for (k=0;k<50;++k){
                for (l=0;l<4;++l){
                    fprintf(file, "%d ", hospitalData->appointment[i][j][k][l]);
                }
            }
        }
    }
    fclose(file);
}

int main() {
    UserData *userData = (UserData *)malloc(sizeof(UserData));
    HospitalData *hospitalData = (HospitalData *)malloc(sizeof(HospitalData));

    memset(userData, 0, sizeof(UserData));
    memset(hospitalData, 0, sizeof(HospitalData));

    loadUserData(userData);
    loadHospitalData(hospitalData);
    
    char dummy [10];
    int homechoice, hospital, vtype, vacc, day, month, year, timeslot, adminchoice, aday, amonth, ayear, atimeslot, admin, avacc, quantity;

    printf("Welcome to Vaccine Management System!\n");
    printf("Enter your user choice: \n(1.) Appointment\n(2.) Admin\n");
    scanf("%d", &homechoice);
    while (homechoice<1||homechoice>2){
        printf("\nInvalid Choice! Please Enter Again.\n");
        scanf("%d", &homechoice);
    }

    switch (homechoice){
        case 1:
        	printf(" ");
        	fgets(dummy,sizeof(dummy),stdin);
            printf("\nEnter your name: ");
            fgets(userData->name, sizeof(userData->name), stdin);
            printf("\nEnter your email: ");
            fgets(userData->email, sizeof(userData->email), stdin);
            printf("\nEnter your phone number: ");
            fgets(userData->phone, sizeof(userData->phone), stdin);

            printf("\nChoose your desired hospital: \n(1.) Aga Khan\n(2.) South City\n(3.) Ziauddin\n");
    scanf("%d",&hospital);
    while((hospital<1)||(hospital>3)){
        printf ("Invalid input! Please enter a valid option.\n");
        scanf("%d",&hospital);
    }
    printf("\nChoose your vaccine type: \n(1.) Covid\n(2.) Polio\n(3.) Tetanus\n");
    scanf("%d",&vtype);
    while((vtype<1)||(vtype>3)){
        printf ("Invalid input! Please enter a valid option.\n");
        scanf("%d",&vtype);
    }
    if (vtype==1){
        printf("\nChoose your desired vaccine:\n(1.) Pfizer\n(2.) Sinovac\n(3.) Moderna\n");
        scanf("%d",&vacc);
        while(vacc<1||vacc>3){
        	printf("Invalid input! Please enter a valid option.\n");
        	scanf("%d",&vacc);
		}
    }
    printf("\nEnter Month of your appointment: ");
    scanf("%d", &month);
    while ((month<1||month>12)){
        printf ("Invalid Month! Please enter a valid month between 1 and 12.\n");
        scanf("%d", &month);
    }
    printf("\nEnter date of your appointment: ");
    scanf("%d", &day);
    while (day<1||day>31){
        printf ("Invalid Day! Please enter a valid day between 1 and 31.\n");
        scanf("%d", &day);
    }
    printf("\nEnter Year of your appointment: ");
    scanf("%d", &year);
    while(year<2024||year>2070){
        printf ("Invalid Year! Please enter a valid year between 2024 and 2070.\n");
        scanf("%d", &year);
    }
    printf("Choose a timeslot:\n(1.) Morning (09:00-12:00)\n(2.) Noon (13:00-16:00)\n(3.) Evening (18:00-21:00)\n");
    scanf("%d",&timeslot);
    while(timeslot<1||timeslot>3){
	    printf("\nInvalid input! Please choose from the options above.\n");
	    scanf("%d",&timeslot);
    }
    printf("\n\nAppointment successfully scheduled!\n");
    printf("-----------------------Appointment Card-----------------------");
            printf("\nDate: %d/%d/%d\t\t\t", day, month, year);
            switch (timeslot) {
                case 1:
                    printf("Time: Morning (09:00 - 12:00)\n");
                    break;
                case 2:
                    printf("Time: Noon (13:00 - 16:00)\n");
                    break;
                case 3:
                    printf("Time: Evening (18:00 - 21:00)\n");
                    break;
            }
            printf("\nName: %s\nEmail: %s\nContact number: %s", userData->name, userData->email, userData->phone);
    switch (hospital){
        case 1:
        switch(vtype){
            case 1:
            switch (vacc){
                case 1:
                printf("\nHospital: Aga Khan\nVaccination type: Covid \nVaccine: Pfizer\n");
                break;
                case 2:
                printf("\nHospital: Aga Khan\nVaccination type: Covid \nVaccine: Sinovac\n");
                break;
                case 3:
                printf("\nHospital: Aga Khan\nVaccination type: Covid \nVaccine: Moderna\n");
                break;
            }
            break;
            case 2:
            printf("\nHospital: Aga Khan\nVaccination type: Polio");
            break;
            case 3:
            printf("\nHospital: Aga Khan\nVaccination type: Tetanus");
            break;
        }
        break;
        case 2:
        switch(vtype){
            case 1:
            switch (vacc){
                case 1:
                printf("\nHospital: South City\nVaccination type: Covid \nVaccine: Pfizer\n");
                break;
                case 2:
                printf("\nHospital: South City\nVaccination type: Covid \nVaccine: Sinovac\n");
                break;
                case 3:
                printf("\nHospital: South City\nVaccination type: Covid \nVaccine: Moderna\n");
                break;
            }
            break;
            case 2:
            printf("\nHospital: South City\nVaccination type: Polio");
            break;
            case 3:
            printf("\nHospital: South City\nVaccination type: Tetanus");
            break;
        }
        break;
        case 3:
        switch(vtype){
            case 1:
            switch (vacc){
                case 1:
                printf("\nHospital: Ziauddin\nVaccination type: Covid \nVaccine: Pfizer\n");
                break;
                case 2:
                printf("\nHospital: Ziauddin\nVaccination type: Covid \nVaccine: Sinovac\n");
                break;
                case 3:
                printf("\nHospital: Ziauddin\nVaccination type: Covid \nVaccine: Moderna\n");
                break;
            }
            break;
            case 2:
            printf("\nHospital: Ziauddin\nVaccination type: Polio");
            break;
            case 3:
            printf("\nHospital: Ziauddin\nVaccination type: Tetanus");
            break;
        }
        break;
    }
        printf("\nHappy Vaccination :)\n");
        printf("----------------------------------------------------------------");
        break;
        case 2:
            printf("\nChoose your hospital: \n(1.) Aga Khan\n(2.) South City\n(3.) Ziauddin\n");
            scanf("%d", &admin);
            while (admin<1||admin>3){
                printf("Invalid input. Please enter again.\n");
                scanf("%d", &admin);
            }

            printf("Enter your choice: \n(1.) View booked appointments\n(2.) Add stock\n");
            scanf("%d", &adminchoice);
            while (adminchoice<1||adminchoice>2){
                printf("Invalid input. Please enter again.\n");
                scanf("%d", &adminchoice);
            }

            switch (adminchoice) {
                case 1:
                    printf("\nEnter Month of the appointment: ");
                    scanf("%d", &amonth);
                    while ((amonth < 1 || amonth > 12)) {
                        printf("Invalid Month! Please enter a valid month between 1 and 12.\n");
                        scanf("%d", &amonth);
                    }
                    printf("\nEnter date of the appointment: ");
                    scanf("%d", &aday);
                    while (aday < 1 || aday > 31) {
                        printf("Invalid Day! Please enter a valid day between 1 and 31.\n");
                        scanf("%d", &aday);
                    }
                    printf("\nEnter Year of the appointment: ");
                    scanf("%d", &ayear);
                    while (ayear < 2024 || ayear > 2070) {
                        printf("Invalid Year! Please enter a valid year between 2024 and 2070.\n");
                        scanf("%d", &ayear);
                    }
                    printf("Choose a timeslot:\n(1.) Morning (09:00-12:00)\n(2.) Noon (13:00-16:00)\n(3.) Evening (18:00-21:00)\n");
                    scanf("%d", &atimeslot);
                    while (atimeslot < 1 || atimeslot > 3) {
                        printf("\nInvalid input! Please choose from the options above.\n");
                        scanf("%d", &atimeslot);
                    }
                    printf("\n%d appointments scheduled\n", hospitalData->appointment[amonth][aday][ayear][atimeslot]);
                    break;
                case 2:
                    printf("\nSelect the vaccine to update stock: \n(1.) Pfizer \n(2.) Sinovac \n(3.) Moderna\n");
                    scanf("%d", &avacc);
                    while (avacc < 1 || avacc > 3) {
                        printf("\nInvalid Input!\nPlease select from the given");
                        scanf("%d", &avacc);
                    }
                    printf("Enter the quantity to add: \n");
                    scanf("%d", &quantity);
                    while (quantity < 0) {
                        printf("\nQuantity cannot be negative. Please enter a positive number.");
                        scanf("%d", &quantity);
                    }
                    printf("Quantity successfully added");
                    hospitalData->vaccine[admin][1][avacc] = hospitalData->vaccine[admin][1][avacc] + quantity;
                    break;
            }
    saveUserData(userData);
    saveHospitalData(hospitalData);
    free(userData);
    free(hospitalData);
    return 0;
    }
}
