namespace DA_LR5;

public class ItemSelecter
{
    public int Select(List<int> probabilities, int probability)
    {
        int itemNumber = 0;
        for (int i = 0; i < probabilities.Count; i++)
        {
            probability -= probabilities[i];

            if (probability <= 0 || i == probabilities.Count - 1)
                break;
            
            itemNumber++;
        }

        return itemNumber;
    }
}