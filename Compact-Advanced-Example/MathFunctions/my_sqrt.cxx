int my_sqrt(double x)
{
    if(x < 0)
        return 0;

    int root;
    for(root = 1; !(root * root > x); ++root);

    return root - 1;
}