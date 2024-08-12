#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void saveNewFile(const std::string &directoryPath, const std::string &oldFilename, const std::string &returnResults)
{
    std::string newFilename = oldFilename.substr(0, oldFilename.find_last_of('.')) + "_converted.csv";
    std::string newFilePath = directoryPath + "/" + newFilename;

    std::ofstream outFile(newFilePath);
    if (outFile.is_open())
    {
        outFile << returnResults;
        outFile.close();
        std::cout << "SUCCESS!!" << std::endl;
    }
    else
    {
        std::cerr << "Error writing contents to file." << std::endl;
    }
}

std::string getPath(const std::string &path, std::string &directoryPath, std::string &oldFilename)
{
    size_t lastSlash = path.find_last_of("/\\");
    if (lastSlash != std::string::npos)
    {
        oldFilename = path.substr(lastSlash + 1);
        directoryPath = path.substr(0, lastSlash);

        if (oldFilename.substr(oldFilename.find_last_of(".") + 1) != "csv")
        {
            std::cerr << "File needs to be in CSV format." << std::endl;
            return "<no contents returned>";
        }

        std::ifstream inFile(path);
        if (inFile.is_open())
        {
            std::stringstream buffer;
            buffer << inFile.rdbuf();
            inFile.close();
            return buffer.str();
        }
        else
        {
            std::cerr << "Error reading file." << std::endl;
        }
    }
    return "<no contents returned>";
}

void doWork(int argc, char *argv[])
{
    if (argc > 1)
    {
        std::string directoryPath, oldFilename;
        std::string path = argv[1];
        std::string fileContents = getPath(path, directoryPath, oldFilename);

        std::stringstream ss(fileContents);
        std::string line;
        std::string returnResult;
        std::string replaceWith;

        while (std::getline(ss, line))
        {
            std::stringstream lineStream(line);
            std::string value;
            std::string processedLine;

            while (std::getline(lineStream, value, ','))
            {
                if (!value.empty())
                {
                    replaceWith = value;
                }
                processedLine.append(replaceWith + ",");
            }
            if (!processedLine.empty())
            {
                processedLine.pop_back(); // Remove the trailing comma
            }
            returnResult.append(processedLine + "\n");
        }

        saveNewFile(directoryPath, oldFilename, returnResult);
    }
    else
    {
        std::cerr << "Usage: ./data_converter <path/to/filename>" << std::endl;
        std::cerr << "Simply drag and drop the file after `./data_converter` to get the correct path and file." << std::endl;
    }
}

int main(int argc, char *argv[])
{
    doWork(argc, argv);
    return 0;
}
