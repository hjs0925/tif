#include <stdio.h>

int main() {
    int list1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int list2[] = {5, 6, 7, 8, 9, 11, 12, 13, 14, 15};
    int target;
    int found = 0;

    printf("타겟을 입력하시오: ");
    scanf("%d", &target);

    int size1 = sizeof(list1) / sizeof(list1[0]);
    int size2 = sizeof(list2) / sizeof(list2[0]);

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            int sum_value = list1[i] + list2[j];
            if (sum_value == target) {
                printf("true: %d (list1[%d]) + %d (list2[%d]) = %d\n", list1[i], i, list2[j], j, sum_value);
                found = 1;
            }
        }
    }

    if (found !=1) {
        printf("false %d\n", target);
    }

    return 0;
}
