RED='\033[0;31m'
GREEN='\033[1;32m'
NC='\033[0m' # No Color
push_swap='./push_swap'

# 5 VALUES
five_values_1="2 5 3 4 1"
five_values_2="-26 -4 -48 -56 -39"
five_values_3="-95 18 -30 -73 31"
five_values_4="21 19 -66 7 78"
five_values_5="8611 -2271 -6004 3325 314"

# 10 Values
ten_values_1="7 4 5 9 1 3 10 8 6 2"
ten_values_2="9 5 10 4 8 2 6 1 7 3"
ten_values_3="10 1 3 6 7 8 5 9 4 2"
ten_values_4="2173 -4522 5468 9164 -7988 -2502 -568 -638 1588 -2666"
ten_values_5="-8337 1247 5327 -618 1128 4324 -6484 -7073 9791 4858"

# 100 Values
hundred_values_1="467 444 159 966 34 293 221 698 624 196 551 45 394 502 515 563 550 254 746 926 331 689 962 19 657 287 114 107 600 264 345 192 735 57 720 456 117 558 266 31 626 120 859 227 479 678 131 434 374 292 0 819 477 378 132 115 162 137 375 74 330 855 505 945 503 307 299 248 653 548 781 267 603 530 392 760 424 362 405 970 351 840 870 874 59 249 813 826 915 610 123 408 16 460 738 119 384 942 793 5"
hundred_values_2="739 806 281 815 952 438 671 916 58 936 19 60 401 372 88 62 654 714 950 617 385 614 675 92 302 160 458 857 89 783 66 834 596 386 540 289 180 551 673 449 332 177 473 246 816 740 342 698 644 997 755 199 83 787 667 115 266 297 519 27 544 152 476 947 683 276 1 710 774 17 72 747 247 364 419"
hundred_values_3="4 420 234 197 294 9 765 13 473 895 570 477 568 340 745 319 120 935 853 668 679 942 443 978 68 392 491 755 363 904 534 820 675 143 690 578 324 701 917 227 742 376 716 21 232 146 968 528 912 731 158 293 521 696 476 131 914 843 109 961 878 585 567 434 546 397 250 545 425 548 285 933 265 101 53 202 906 937 600 374 7 466 632 457 813 79 715 575 730 287 792 915 423 408 606 540 71 628 966 746"
hundred_values_4="554 158 848 877 34 811 44 301 503 888 698 588 280 922 78 661 377 443 292 780 953 383 528 566 162 693 163 997 658 123 671 788 272 735 887 363 313 318 456 83 901 124 406 25 117 249 600 136 759 745 515 283 481 682 932 782 871 988 921 690 603 960 717 268 231 783 833 73 419 494 564 327 991 653 792 295 358 128 263 799 24 457 621 691 51 912 562 200 385 954 574 303 455 444 747 825 171 544 506 114"

# 500 Values
fivehundred_values_1="973 206 543 366 237 605 253 680 448 97 731 235 717 86 959 565 550 903 88 762 445 416 599 672 886 421 880 740 489 812 662 630 214 686 401 347 994 668 568 8 502 216 336 698 917 723 469 219 894 45 648 397 841 759 663 566 461 259 910 109 779 548 982 322 646 108 50 241 546 576 614 475 846 946 951 484 435 143 328 877 211 766 647 174 678 823 494 878 797 862 685 11 127 725 881 315 131 700 612 616 164 144 80 586 254 498 332 810 43 446 573 354 410 815 804 803 342 355 238 331 25 480 422 434 955 132 767 825 838 874 310 459 968 506 820 301 290 824 593 55 419 212 916 726 572 625 0 182 778 547 527 735 125 308 248 154 242 463 404 756 230 957 809 352 529 996 507 719 819 213 150 61 741 321 872 199 667 539 732 949 70 818 115 679 273 990 799 953 609 692 296 425 1000 173 736 900 90 753 207 744 751 849 746 856 962 12 378 392 314 289 979 503 577 699 139 553 656 231 37 791 41 792 38 832 95 67 718 265 544 991 153 671 631 245 27 924 940 129 390 534 617 834 444 19 992 285 620 329 813 360 24 805 256 865 234 224 46 798 829 209 467 808 749 470 578 23 499 171 554 775 362 361 117 569 175 373 40 482 794 814 227 368 847 250 921 752 411 487 415 110 201 837 178 669 100 845 592 483 504 431 408 94 975 75 974 585 344 420 170 690 456 102 383 739 2 868 674 157 276 774 128 488 400 356 643 59 35 897 981 796 844 142 945 978 266 597 306 655 85 73 512 653 683 927 963 192 729 269 221 188 255 77 208 633 728 334 882 581 427 7 30 3 471 555 106 754 263 954 220 177 29 147 136 6 522 941 282 433 103 899 516 781 660 610 288 833 533 464 817 716 491 200 160 34 13 168 885 440 948 567 536 524 294 91 816 223 733 795 854 155 863 116 835 866 376 359 258 442 514 582 673 645 53 613 133 944 967 890 755 377 896 28 980 357 450 72 950 989 907 17 500 523 156 911 541 891 840 722 22 186 18 31 190 107 210 271 644 563 280 575 1 120 852 137 161 274 324 81 305 889 341 591 706 528 943 761 478 14 228 827 222 249 281 497 913 589 629 745 695 742 928 564 119 443 584 381 486 583 63 382"
fivehundred_values_2="991 283 750 327 424 144 173 572 908 802 625 387 738 865 414 93 698 238 352 542 109 744 551 536 145 904 541 975 901 305 824 648 148 249 732 443 135 155 665 949 964 290 891 447 961 441 751 217 153 609 325 821 903 691 922 205 265 841 544 513 566 915 89 33 623 363 440 274 785 96 27 580 372 211 136 943 814 877 892 767 113 310 95 346 895 210 152 147 947 578 724 888 747 41 384 354 557 99 704 472 537 518 419 417 779 713 529 798 251 184 652 53 662 376 706 175 120 268 939 100 286 361 344 233 54 925 3 942 959 936 709 603 913 644 161 452 281 614 388 377 59 898 487 504 715 983 449 813 119 454 638 225 863 607 383 35 266 90 49 946 68 282 564 857 790 853 51 430 267 624 104 368 639 103 823 242 716 436 115 873 220 543 379 938 397 500 297 461 900 386 830 359 558 318 797 560 804 579 633 469 924 596 78 302 65 141 869 503 389 693 501 462 562 85 206 403 257 429 410 702 655 809 761 860 328 476 699 14 563 526 87 923 597 34 743 916 515 521 288 722 227 415 301 768 508 616 300 714 755 390 680 986 9 181 818 886 358 827 182 189 739 703 700 442 622 538 168 30 126 918 787 990 602 492 977 968 445 956 11 974 192 825 945 933 456 842 229 343 660 972 753 499 245 38 223 25 292 172 319 844 540 232 982 506 994 92 382 919 612 520 158 269 226 979 106 413 427 930 207 571 635 735 686 682 190 775 856 966 188 133 661 396 970 404 837 679 107 796 493 44 854 733 653 976 159 605 345 846 658 157 944 987 160 17 637 6 484 129 997 721 574 394 595 884 675 105 178 641 466 932 48 329 519 293 800 407 561 836 911 948 495 931 64 235 889 236 559 62 882 784 611 374 907 294 770 780 522 98 471 803 832 56 481 234 801 849 657 276 480 405 852 67 762 678 600 488 32 228 127 393 277 654 209 880 788 365 5 137 690 140 650 692 91 645 203 604 433 428 592 375 323 610 707 906 708 759 406 199 935 330 718 874 993 198 870 565 317 111 326 284 204 489 910 58 839 631 618 468 940 547 369 887 883 373 138 905 728 971 77 176 239 734 793 777 254 958 156 340 12 789 973 627 490 194 831 912 792 590 385 392"
fivehundred_values_3="230 243 442 540 584 417 290 461 33 604 477 123 677 770 942 951 580 620 25 985 781 872 553 116 967 550 869 215 234 194 189 910 419 478 232 220 212 547 565 563 201 410 368 814 859 103 825 395 422 404 861 298 82 885 743 239 381 178 556 504 261 656 783 993 725 370 21 598 512 927 245 489 534 435 595 492 739 246 754 900 248 225 976 688 73 916 185 915 508 786 286 757 287 332 117 187 475 505 817 789 936 46 675 831 880 808 847 269 657 196 554 619 758 840 568 991 264 742 226 558 228 115 441 312 199 899 251 385 375 249 202 943 411 424 968 945 818 581 497 857 183 957 265 100 815 305 685 340 429 948 207 463 709 841 961 335 101 551 727 615 625 924 745 867 253 91 105 893 59 414 569 257 85 665 836 669 544 772 20 806 69 926 764 693 63 459 805 988 600 293 348 32 888 420 224 483 71 371 519 866 282 470 283 273 62 587 86 87 714 159 453 5 486 34 705 522 285 793 106 566 415 970 158 652 901 876 107 506 509 498 983 164 121 188 638 391 54 699 820 571 360 76 344 617 45 326 267 827 22 542 644 582 396 13 855 905 139 695 58 186 310 629 430 607 878 79 873 176 507 750 359 272 785 53 36 403 622 493 829 393 839 72 104 380 959 774 902 60 421 663 80 401 210 659 850 779 679 30 406 877 710 437 535 468 631 701 561 445 863 440 694 169 989 921 154 275 28 496 614 469 52 539 769 720 907 655 623 55 717 802 288 613 868 627 792 784 402 128 583 766 466 345 843 602 433 452 177 662 160 65 337 124 495 374 692 874 130 219 960 319 408 262 852 244 409 892 148 749 133 689 549 862 336 776 341 767 330 651 152 259 351 917 683 648 824 350 516 914 940 299 292 771 947 533 698 719 975 796 628 84 882 432 798 278 971 142 427 738 828 200 303 881 923 484 193 658 145 502 618 853 258 871 488 608 134 81 653 939 173 157 296 790 723 18 543 579 647 654 367 252 366 263 342 270 456 499 609 606 696 804 168 238 830 397 636 198 42 577 953 175 996 446 7 944 992 821 704 163 138 357 626 511 95 797 372 129 418 884 777 114 481 450 722 317 144 635 517 782 480 963 937 255 388 192 812 316 216 218 324 40"

# thousand_values_1="877 643 645 303 257 804 874 377 163 815 470 402 162 256 794 431 241 41 84 762 823 197 40 871 405 516 548 928 513 843 169 455 820 951 728 138 32 924 112 447 444 768 700 887 189 704 556 754 261 105 584 496 663 708 315 983 70 282 993 436 50 319 20 131 114 79 175 967 213 511 759 956 285 711 646 647 420 568 918 800 574 353 995 870 588 88 270 687 830 908 380 458 992 293 566 936 610 606 125 915 306 523 136 798 253 836 346 639 29 66 255 854 565 309 503 734 743 966 486 347 716 288 361 143 994 200 374 982 373 837 370 795 941 729 378 418 52 662 272 839 869 468 534 812 396 717 35 738 790 719 884 530 335 299 638 437 618 61 745 543 597 498 340 701 327 99 680 107 671 580 116 354 96 682 883 85 473 532 603 18 268 94 394 576 89 929 298 882 592 225 913 54 8 950 635 355 185 668 786 709 5 541 117 464 358 491 585 53 842 334 847 72 167 133 660 139 586 239 733 607 582 637 203 476 539 827 863 817 517 756 186 720 775 325 520 134 71 210 999 497 816 119 906 752 750 188 292 621 747 851 553 333 446 942 406 260 690 985 751 864 135 852 730 181 453 631 386 47 718 861 126 313 784 422 488 803 209 477 45 831 202 617 946 896 142 527 461 808 572 667 300 277 98 922 818 259 19 80 963 291 689 672 948 191 403 521 187 914 744 419 866 560 506 10 943 782 766 365 575 23 400 364 34 342 46 77 962 715 518 429 563 480 102 68 596 371 307 763 323 892 849 424 741 48 302 382 352 314 118 286 806 801 294 765 388 778 12 158 834 265 542 559 630 123 640 100 16 557 526 938 283 780 678 891 958 218 244 31 233 581 702 141 414 73 87 723 75 499 510 990 449 770 749 509 659 441 153 925 522 26 757 145 591 602 536 448 409 598 224 538 401 475 208 748 269 108 712 674 930 558 164 583 104 856 469 1000 551 192 173 664 777 147 227 552 238 245 681 180 600 442 832 304 184 625 357 665 686 601 432 612 767 862 595 376 732 494 392 753 156 797 356 737 221 264 901 634 968 55 462 434 722 705 927 644 408 860 421 726 206 369 972 174 428 42 91 368 916 345 395 955 920 331 934 988 435 120 305 721 567 528 714 0 78 168 326 905 171 961 547 263 217 998 890 571 280 504 207 27 28 698 688 648 318 628 140 533 976 266 699 675 940 813 258 226 457 215 450 549 487 811 472 372 573 661 38 633 398 246 367 654 397 947 416 880 220 819 407 980 151 320 984 910 440 58 627 899 881 243 157 562 279 165 427 387 740 710 337 247 959 656 64 127 276 383 176 895 308 44 821 926 897 776 724 482 964 65 415 844 278 953 456 214 945 36 237 853 587 33 2 807 132 204 564 384 90 599 4 609 150 684 161 838 63 760 531 937 332 590 611 579 848 649 290 484 60 971 670 695 975 772 229 626 296 95 696 713 771 404 490 991 249 144 736 341 570 86 467 248 502 505 389 328 160 359 234 764 613 391 512 755 301 22 657 59 867 492 57 471 989 859 324 362 438 855 21 410 193 321 872 685 707 525 673 82 986 965 13 146 857 360 11 954 349 623 761 284 159 919 329 311 330 577 739 182 561 835 297 850 343 515 211 393 254 917 978 791 122 412 912 479 810 201 907 921 846 508 252 658 615 676 828 535 489 666 216 981 129 39 9 430 196 25 445 51 555 242 655 485 697 537 478 316 97 295 251 546 495 893 465 614 460 783 195 540 67 236 792 787 840 703 758 875 785 677 379 809 273 148 385 49 622 74 411 128 693 868 608 199 911 691 619 76 977 155 366 154 124 493 17 825 15 909 310 878 683 781 83 969 735 350 620 894 569 1 706 322 190 742 69 130 960 944 390 115 679 952 451 250 312 101 973 111 223 865 833 824 858 121 805 3 274 183 348 228 974 137 888 423 669 996 731 170 879 351 652 694 43 773 793 339 363 873 692 426 789 885 841 829 997 179 113 604 222 933 336 774 483 375 900 338 822 949 92 240 746 103 230 344 970 417 466 802 769 231 651 454 624 452 7 262 594 172 474 957 413 903 779 56 550 152 650 814 799 501 481 93 399 6 923 106 232 616 876 987 932 267 524 425 166 889 463 500 149 81 110 433 904 589 886 289 593 826 788 235 507 636 219 845 578 37 519 177 109 544 931 14 271 459 641 514 898 653 529 62 24 381 545 554 439 317 178 979 30 194 632 443 275 281 629 198 287 205 796 902 727 939 725 212 605 935"

echo "===== ${RED}5 values #1${NC} ====="
# $push_swap 1 5 2 4 0
printf "${GREEN}Operation count =>${NC}";$push_swap $five_values_1 | wc -l

echo "===== ${RED}5 values #2${NC} ====="
# $push_swap 1 5 2 4 0
printf "${GREEN}Operation count =>${NC}";$push_swap $five_values_2 | wc -l

echo "===== ${RED}5 values #3${NC} ====="
# $push_swap 1 5 2 4 0
printf "${GREEN}Operation count =>${NC}";$push_swap $five_values_3 | wc -l

echo "===== ${RED}5 values #4${NC} ====="
# $push_swap 1 5 2 4 0
printf "${GREEN}Operation count =>${NC}";$push_swap $five_values_4 | wc -l

echo "===== ${RED}5 values #5${NC} ====="
# $push_swap 1 5 2 4 0
printf "${GREEN}Operation count =>${NC}";$push_swap $five_values_5 | wc -l
echo ""
echo "===== ${RED}#1 10 values${NC} ====="
# $push_swap 593 293 422 788 28 287 856 763 447 284
printf "${GREEN}Operation count =>${NC}";$push_swap $ten_values_1 | wc -l

echo "===== ${RED}#2 10 values${NC} ====="
# $push_swap 593 293 422 788 28 287 856 763 447 284
printf "${GREEN}Operation count =>${NC}";$push_swap $ten_values_2 | wc -l

echo "===== ${RED}#3 10 values${NC} ====="
# $push_swap 593 293 422 788 28 287 856 763 447 284
printf "${GREEN}Operation count =>${NC}";$push_swap $ten_values_3 | wc -l

echo "===== ${RED}#4 10 values${NC} ====="
# $push_swap 593 293 422 788 28 287 856 763 447 284
printf "${GREEN}Operation count =>${NC}";$push_swap $ten_values_4 | wc -l

echo "===== ${RED}#5 10 values${NC} ====="
# $push_swap 593 293 422 788 28 287 856 763 447 284
printf "${GREEN}Operation count =>${NC}";$push_swap $ten_values_5 | wc -l
echo ""
echo "===== ${RED}100 values${NC} ====="
printf "${GREEN}Operation count =>${NC}";$push_swap $hundred_values_1 | wc -l

echo "===== ${RED}100 values${NC} ====="
printf "${GREEN}Operation count =>${NC}";$push_swap $hundred_values_2 | wc -l

echo "===== ${RED}100 values${NC} ====="
printf "${GREEN}Operation count =>${NC}";$push_swap $hundred_values_3 | wc -l

echo "===== ${RED}100 values${NC} ====="
printf "${GREEN}Operation count =>${NC}";$push_swap $hundred_values_4 | wc -l
echo ""
echo "===== ${RED}500 values${NC} ====="
printf "${GREEN}Operation count =>${NC}";$push_swap $fivehundred_values_1 | wc -l
echo "===== ${RED}500 values${NC} ====="
printf "${GREEN}Operation count =>${NC}";$push_swap $fivehundred_values_2 | wc -l

echo "===== ${RED}500 values${NC} ====="
printf "${GREEN}Operation count =>${NC}";$push_swap $fivehundred_values_3 | wc -l

# echo "===== ${RED}Testing with 1000 values${NC} ====="
# echo "${RED}Operation count${NC}";$push_swap $thousand_values_1 | wc -l