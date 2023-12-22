namespace DA_LR5;

public class ItemsManager
{
    public List<Item> Items(List<Item> items, int numItem, int maxWeight, int maxCost)
    {
        ItemGenerator itemGenerator = new ItemGenerator();
        UserInputItems userInputItems = new UserInputItems();
        bool again = !(items.Count == 0);
        MassageWriter.Write(again ? Massages.ItemsManagerAgain : Massages.ItemsManager);


        bool correctEnter = false;
        string input = string.Empty;
        while (!correctEnter)
        {
            input = Console.ReadLine() ?? string.Empty;
            if (input == "1")
            {
                items = userInputItems.Input(numItem);
                correctEnter = true;
            }
            else if (input == "2")
            {
                items = itemGenerator.Generate(numItem, maxWeight, maxCost);
                correctEnter = true;
            }
            else if (again && input == "3")
            {
                correctEnter = true;
            }
            else
                MassageWriter.Write(Massages.IncorrectInput);
        }

        return items;
    }
}