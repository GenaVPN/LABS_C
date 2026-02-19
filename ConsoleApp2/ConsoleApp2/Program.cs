using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class Program
    {

        private int x, y, z;
        private double x1, y1, z1;

        public int difference(int x, int y, int z) {
            return x - y - z;
        }
        public int pr(int x, int y, int z)
        {
            int otv = x*y*z;
            return otv;
        }
        public int sum(int x, int y, int z)
        {
            int otv = x +y+z;
            return otv;
        }
        public double sum(double x, double y, double z)
        {
            double otv = x + y + z;
            return otv;
        }
        public double difference(double x, double y, double z)
        {
            double otv = x - y - z;
            return otv;
        }

        public double pr(double x, double y, double z)
        {
            return x * y * z;
        }

        public double delen(double x, double y)
        {
            if (y == 0)
            {
                Console.WriteLine("Ошибка!!! Деление на 0.");
                return 0;
            }
            else return x / y;
        }

        public int delen(int x, int y)
        {
            if (y == 0)
            {
                Console.WriteLine("Ошибка!!! Деление на 0.");
                return 0;
            }
            else return x / y;
        }
       


    

        public void setData()
        {
            Console.WriteLine("Введите 3 целых числа x,y,z: ");
            while (true)
            {
                try
                {
                    Console.Write("x = ");
                    x = int.Parse(Console.ReadLine());
                    Console.Write("y = ");
                    y = int.Parse(Console.ReadLine());
                    Console.Write("z = ");
                    z = int.Parse(Console.ReadLine());
                    break;
                }
                catch (Exception)
                {

                    Console.WriteLine("Неверный ввод данных. Повторите попытку!");
                }
            }

            Console.WriteLine("Введите 3 вещественных числа x1,y1,z1: ");
            while (true)
            {
                try
                {
                    Console.Write("x1 = ");
                    x1 = float.Parse(Console.ReadLine());
                    Console.Write("y1 = ");
                    y1 = float.Parse(Console.ReadLine());
                    Console.Write("z1 = ");
                    z1 = float.Parse(Console.ReadLine());
                    break;
                }
                catch (Exception)
                {
                    Console.WriteLine("Неверный ввод данных. Повторите попытку!");
                }
            }

        }

        public void task()
        {
            setData();

     
            Console.WriteLine("Задание а. {0} - {1} - {2} = {3}", x,y,z, difference(x,y,z));
            Console.WriteLine("Задание б. {0} * {1} * {2} = {3}", x, y, z, pr(x, y, z));
            Console.WriteLine("Задание в. {0} + {1} + {2} = {3}", x, y, z, sum(x, y, z));
            Console.WriteLine("Задание г. {0:F2} + {1:F2} + {2:F2} = {3:F2}", x1, y1, z1, sum(x1, y1, z1));
            Console.WriteLine("Задание д. {0:F2} - {1:F2} - {2:F2} = {3:F2}", x1, y1, z1, difference(x1, y1, z1));
            Console.WriteLine("Задание е. {0:F2} * {1:F2} * {2:F2} = {3:F2}", x1, y1, z1, pr(x1, y1, z1));
            Console.WriteLine("Задание ж. {0} / {1} = {2}", x, y, delen(x, y));
            Console.WriteLine("Задание з. {0:F2} / {1:F2} = {2:F2}", x1, y1, delen(x1, y1));

        }


        static void Main(string[] args)
        {
            Program s = new Program();
            s.task();
        }
    }
}
