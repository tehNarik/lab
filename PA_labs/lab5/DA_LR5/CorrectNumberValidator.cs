namespace DA_LR5;

public class CorrectNumberValidator : ValidatorBase
{
    public override Dictionary<string, string> HandleValidation(string inputPazzle, int size)
    {
        string[] splitInput = inputPazzle.Split();
        int[] numbers = new int[splitInput.Length];
        for (int i = 0; i < splitInput.Length; i++)
        {
            numbers[i] = int.Parse(splitInput[i]);
        }

        for (int i = 0; i < numbers.Length; i++)
        {
            if (numbers[i] < 1 || numbers[i] > 1000)
            {
                ErrorsResult.Add("incorrect numbers", "you have entered incorrect numbers, they must be in the specified range without repetitions");
                return ErrorsResult;
            }
        }

        if (Successor != null)
            return Successor.HandleValidation(inputPazzle, size);

        return ErrorsResult;
    }
}