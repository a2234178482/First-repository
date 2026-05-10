int CheckDuplicate(DiseaseList* nb, Disease new_disease) {
    for (int i = 0; i < nb->length; i++) {
        if (nb->data[i].id == new_disease.id) {
            return i;
        }
        if (strstr(nb->data[i].name, new_disease.name) ||
            strstr(new_disease.name, nb->data[i].name)) {
            return i;
        }
    }
    return -1;
}
int SafeInsertDisease(DiseaseList* nb, Disease new_disease) {
    int conflict_pos = CheckDuplicate(nb, new_disease);
    if (conflict_pos >= 0) {
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            nb->data[conflict_pos] = new_disease;
            return 1;
        case 2:
            scanf("%d", &new_disease.id);
            return InsertDisease(nb, new_disease);
        default:
            return 0;
        }
    }
    return InsertDisease(nb, new_disease);
}