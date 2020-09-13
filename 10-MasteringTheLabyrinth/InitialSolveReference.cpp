RelativeDirection getSolveDirection(int availableDirections)
{
    if (availableDirections & Left)
    {
        return Left;
    }
    else if (availableDirections & Forward)
    {
        return Forward;
    }
    else if (availableDirections & Right)
    {
        return Right;
    }
    else
    {
        return Backward;
    }
}