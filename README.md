# Disease Hospital with System Programming

Uses lists hashtables and avl trees to manage a hospital with patients.
Can print results if a query is given.


sdi1600278 Στεβής Χαράλαμπος-Αντώνιος
Προγραμματισμός Συστήματος Εργασία 1η.

Αφού γίνει make το πρόγραμμα τρέχει με τη εξής εντολή:
./diseaseMonitor -p data.txt -h1 10 -h2 10 -b 16
Το αρχείο από το οποίο τρέχουμε είναι το data.txt.
Σημείωση για το bucketsize στο τέλος του readme.

Παρακάτω περιγράφεται το πρόγραμμα, τι περιέχει και πώς λειτουργεί.

Στον φάκελο περιέχονται τα εξής:
Makefile - Για compile
Φάκελος SRC - Περιέχει όλα τα .c αρχεία
    avl.c/date.c/hash.c/list.c/main.c/patient.c
Φάκελος HEADERS - Περιέχει όλα τα .h αρχεία
    avl.h/date.h/hash.h/list.h/patient.h
Φάκελος BUILD - Περιέχει όλα τα .ο αρχεία αφού εκτελεστεί το make, από το makefile
Φάκελος TXT - Περιέχει το αρχείο κειμένου από το οποίο διαβάζονται οι ασθενείς

Μιλώντας για κάθε δομή ξεχωριστά:

    PATIENT (patient.h/patient.c)
Τα αρχεία αυτά έχουν την δυνατότητα να διαβάζουν μια γραμμή από ένα αρχείο, να αρχικοποιούν ένα ασθενή, να τον εκτυπώνουν και να τον διαγράφουν.

    LIST (list.h/list.c)
Τα αρχεία αυτά έχουν την δυνατότητα να αρχικοποιούν μια λίστα, να την επεκτείνουν, να την εκτυπώνουν και να την διαγράφουν. Επίσης υπάρχει η δυνατότητα να ψάχνουμε αν υπάρχει ένα στοιχείο μέσα στην λίστα. Πχ χρησιμοποιείται για ελέγχους σε διπλότυπα recordID.

    DATE (date.h/date.c)
Τα αρχεία αυτά έχουν την δυνατότητα να συγκρίνουν δύο ημερομηνίες. Αφού τις δεχτούν, τις κομματιάζουν και κάνουν return ανάλογα με το αποτέλεσμα της σύγκρισης. Πιο συγκεκριμένα επιστρέφει -1 αν το exitDate είναι - ή αν το date2>date1, 1 αν date1>date2 και 0 αν date1=date2.

    AVL (avl.h/alv.c)
Τα αρχεία αυτά δημιουργούν avl δέντρα. Μπορούν να κάνουν αρχικοποίηση,εκτύπωση,διαγραφη. Επίσης έχουμε εισαγωγές σε δέντρο,εισαγωγή σε κόμβο και δημιουργία νέου κόμβου. Ακόμα έχουμε συναρτήσεις για rotates ώστε τα δέντρα να είναι ισοζυγισμένα, συνάρτηση που βρίσκει το ύψος του δέντρου, συνάρτηση που βρίσκει το μαξ δύο αριθμών(χρησιμοποιείται στο για το ύψος του δέντρου) και δύο συναρτήσεις για το πόσους κόμβους έχει ένα δέντρο.

    HASH (hash.h/hash.c)
Τα αρχεία αυτά μπορούν να διαχειρίζονται hashtables. Κάθε hashtable αποτελείται από hashbuckets και μέσα σε κάθε hashbucket υπάρχει μια δομή bucketarray. Τα hashtables μπορούν να αρχικοποιηθούν,διαγραφούν,εκτυπωθούν. Τα hashbuckets μπορούν να αρχικοποιηθούν,εκτυπωθούν,διαγραφούν. Τα bucketarrays μπορούν να αρχικοποιηθούν,διαγραφούν,εκτυπωθούν. Υπάρχει hashfunction μέσω την οποία γίνεται to hashing. Οι εισαγωγές νέων buckets γίνονται αν ο προηγούμενος έχει γεμίσει

Μέσα σε αυτό το αρχείο περιέχονται και τα queries.
Το globalDiseaseStats εκτυπώνει όλους τους ασθενείς σε κάθε ασθένεια. Αν δοθούν ημερομηνίες γίνονται οι κατάλληλες συγκρίσεις και εκτυπώνονται μόνο αυτά που πρέπει.(νομίζω λειτουργεί σωστά).
Το diseaseFrequency εκτυπώνει του ασθενείς με μια συγκεκριμένη ασθένεια.(δεν λειτουργεί σωστά).
Το insertPatientRecord δημιουργεί ένα ασθενεί και το προσθέτει στη λίστα, και στα δύο hashtables(disease,countr).(λειτουργεί σωστά.
Το recordPatientExit που αλλάζει το exitDate ενός ασθενεί(λειτουργεί περίπου σωστά)
Το numCurrentPatients που εκτυπώνει πόσοι ασθενείς νοσηλεύονται ακόμα.(δεν λειτουργεί σωστά).

    MAIN (main.c)
Στο αρχείο αυτό τρέχει το κυρίως πρόγραμμα. Ανοίγει και διαβάζει ένα αρχείο με strings ασθενών. Δημιουργεί μία λίστα και δύο hashtables. Αποθηκεύει του ασθενείς στην λίστα και στα hashtables. Τρέχει μία λούπα για τα queries που δίνουμε στο input
και ανάλογα καλούμε την κάθε εκδοχή τους. Τέλος ελευθερώνουμε ότι έχουν δεσμεύσει.

Στην εργασία δεν περιέχεται υλοποίηση του heap καθώς και τα queries που το απαιτούν.
To bucketsize που μπορεί να δοθεί είναι συγκεκριμένο και είναι 16. Αυτό συμβαίνει επειδή η δομή bucketarray είναι των 16 bits. Δοκίμασα και με πολλ/σια του 16 αλλά δεν μου έβγαινε σωστό.



sdi1600278 Στεβής Χαράλαμπος-Αντώνιος
Προγραμματισμός Συστήματος Εργασία 1η.

Αφού γίνει make το πρόγραμμα τρέχει με τη εξής εντολή:
./diseaseMonitor -p data.txt -h1 10 -h2 10 -b 16
Το αρχείο από το οποίο τρέχουμε είναι το data.txt.
Σημείωση για το bucketsize στο τέλος του readme.

Παρακάτω περιγράφεται το πρόγραμμα, τι περιέχει και πώς λειτουργεί.

Στον φάκελο περιέχονται τα εξής:
Makefile - Για compile
Φάκελος SRC - Περιέχει όλα τα .c αρχεία
    avl.c/date.c/hash.c/list.c/main.c/patient.c
Φάκελος HEADERS - Περιέχει όλα τα .h αρχεία
    avl.h/date.h/hash.h/list.h/patient.h
Φάκελος BUILD - Περιέχει όλα τα .ο αρχεία αφού εκτελεστεί το make, από το makefile
Φάκελος TXT - Περιέχει το αρχείο κειμένου από το οποίο διαβάζονται οι ασθενείς

Μιλώντας για κάθε δομή ξεχωριστά:

    PATIENT (patient.h/patient.c)
Τα αρχεία αυτά έχουν την δυνατότητα να διαβάζουν μια γραμμή από ένα αρχείο, να αρχικοποιούν ένα ασθενή, να τον εκτυπώνουν και να τον διαγράφουν.

    LIST (list.h/list.c)
Τα αρχεία αυτά έχουν την δυνατότητα να αρχικοποιούν μια λίστα, να την επεκτείνουν, να την εκτυπώνουν και να την διαγράφουν. Επίσης υπάρχει η δυνατότητα να ψάχνουμε αν υπάρχει ένα στοιχείο μέσα στην λίστα. Πχ χρησιμοποιείται για ελέγχους σε διπλότυπα recordID.

    DATE (date.h/date.c)
Τα αρχεία αυτά έχουν την δυνατότητα να συγκρίνουν δύο ημερομηνίες. Αφού τις δεχτούν, τις κομματιάζουν και κάνουν return ανάλογα με το αποτέλεσμα της σύγκρισης. Πιο συγκεκριμένα επιστρέφει -1 αν το exitDate είναι - ή αν το date2>date1, 1 αν date1>date2 και 0 αν date1=date2.

    AVL (avl.h/alv.c)
Τα αρχεία αυτά δημιουργούν avl δέντρα. Μπορούν να κάνουν αρχικοποίηση,εκτύπωση,διαγραφη. Επίσης έχουμε εισαγωγές σε δέντρο,εισαγωγή σε κόμβο και δημιουργία νέου κόμβου. Ακόμα έχουμε συναρτήσεις για rotates ώστε τα δέντρα να είναι ισοζυγισμένα, συνάρτηση που βρίσκει το ύψος του δέντρου, συνάρτηση που βρίσκει το μαξ δύο αριθμών(χρησιμοποιείται στο για το ύψος του δέντρου) και δύο συναρτήσεις για το πόσους κόμβους έχει ένα δέντρο.

    HASH (hash.h/hash.c)
Τα αρχεία αυτά μπορούν να διαχειρίζονται hashtables. Κάθε hashtable αποτελείται από hashbuckets και μέσα σε κάθε hashbucket υπάρχει μια δομή bucketarray. Τα hashtables μπορούν να αρχικοποιηθούν,διαγραφούν,εκτυπωθούν. Τα hashbuckets μπορούν να αρχικοποιηθούν,εκτυπωθούν,διαγραφούν. Τα bucketarrays μπορούν να αρχικοποιηθούν,διαγραφούν,εκτυπωθούν. Υπάρχει hashfunction μέσω την οποία γίνεται to hashing. Οι εισαγωγές νέων buckets γίνονται αν ο προηγούμενος έχει γεμίσει

Μέσα σε αυτό το αρχείο περιέχονται και τα queries.
Το globalDiseaseStats εκτυπώνει όλους τους ασθενείς σε κάθε ασθένεια. Αν δοθούν ημερομηνίες γίνονται οι κατάλληλες συγκρίσεις και εκτυπώνονται μόνο αυτά που πρέπει.(νομίζω λειτουργεί σωστά).
Το diseaseFrequency εκτυπώνει του ασθενείς με μια συγκεκριμένη ασθένεια.(δεν λειτουργεί σωστά).
Το insertPatientRecord δημιουργεί ένα ασθενεί και το προσθέτει στη λίστα, και στα δύο hashtables(disease,countr).(λειτουργεί σωστά.
Το recordPatientExit που αλλάζει το exitDate ενός ασθενεί(λειτουργεί περίπου σωστά)
Το numCurrentPatients που εκτυπώνει πόσοι ασθενείς νοσηλεύονται ακόμα.(δεν λειτουργεί σωστά).

    MAIN (main.c)
Στο αρχείο αυτό τρέχει το κυρίως πρόγραμμα. Ανοίγει και διαβάζει ένα αρχείο με strings ασθενών. Δημιουργεί μία λίστα και δύο hashtables. Αποθηκεύει του ασθενείς στην λίστα και στα hashtables. Τρέχει μία λούπα για τα queries που δίνουμε στο input
και ανάλογα καλούμε την κάθε εκδοχή τους. Τέλος ελευθερώνουμε ότι έχουν δεσμεύσει.

Στην εργασία δεν περιέχεται υλοποίηση του heap καθώς και τα queries που το απαιτούν.
To bucketsize που μπορεί να δοθεί είναι συγκεκριμένο και είναι 16. Αυτό συμβαίνει επειδή η δομή bucketarray είναι των 16 bits. Δοκίμασα και με πολλ/σια του 16 αλλά δεν μου έβγαινε σωστό.



