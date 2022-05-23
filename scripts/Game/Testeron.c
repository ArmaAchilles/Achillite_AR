class Testeron : Managed
{
	protected array<int> m_IntArray;
	protected int m_Int;
	void Testeron(array<int> arr)
	{
		m_IntArray = arr;
		if (arr.Count() > 1)
			m_Int = arr[0];
	}
	void Print()
	{
		PrintFormat("{{%1}, %2}}", m_IntArray, m_Int);
	}
}

void main()
{
	array<int> arr = {3, 2, 1};
	Testeron testeron = Testeron(arr);
	testeron.Print();
};