namespace DA_LR5;

public class CorrectNumberItemValidator : ValidatorBase
{
    public override Dictionary<string, string> HandleValidation(string inputPazzle, int size)
    {
        string[] splitInput = inputPazzle.Split();
        int[] numbers = new int[splitInput.Length];
        for (int i = 0; i < splitInput.Length; i++)
        {
            numbers[i] = int.Parse(splitInput[i]);
        }


        if (numbers[0] < 1 || numbers[0] > 20)
        {
            ErrorsResult.Add("incorrect numbers",
                "you have entered incorrect numbers, they must be in the specified range without repetitions");
            return ErrorsResult;
        }

        if (numbers[1] < 2 || numbers[1] > 30)
        {
            ErrorsResult.Add("incorrect numbers",
                "you have entered incorrect numbers, they must be in the specified range without repetitions");
            return ErrorsResult;
        }

        if (Successor != null)
            return Successor.HandleValidation(inputPazzle, size);

        return ErrorsResult;
    }
}