#pragma once
#include <msclr/marshal_cppstd.h>
#include<vcclr.h>
//#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include <Wininet.h>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <regex>
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include "DataUtils/DataLoader.h"
#include "DataUtils/DataPreprocessor.h"
#include "Utils/SimilarityFunctions.h"
#include "Utils/PCADimensionalityReduction.h"
#include "Evaluation/Metrics.h"
#include "Evaluation/Metrics.h"
#include "Classification/KNNClassifier.h"
#include "Classification/DecisionTreeClassification.h"
#include "Regression/KNNRegression.h"
#include "Regression/DecisionTreeRegression.h"
#include "Clustering/KMeans.h"
#include "Clustering/FuzzyCMeans.h"
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <Eigen/SVD>
#include "Regression/LinearRegression.h"
#include "Classification/LogisticRegression.h"





namespace MachineLearningLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ mainTabControl;
	private: System::Windows::Forms::TabPage^ classificationTabPage;
	private: System::Windows::Forms::TabPage^ regressionTabPage;
	private: System::Windows::Forms::TabPage^ clusteringTabPage;
	private: System::Windows::Forms::Button^ calassificationRunButton;


	private: System::Windows::Forms::TextBox^ classificationDataPathTextBox;


	private: System::Windows::Forms::ListBox^ classificationAlgorithmListBox;
	private: System::Windows::Forms::Label^ calssificationSelectAlgorithmLabel;
	private: System::Windows::Forms::Label^ classificationDataURLLabel;
	private: System::Windows::Forms::Button^ regressionRuntButton;
	private: System::Windows::Forms::TextBox^ regressionDataPathTextBox;



	private: System::Windows::Forms::ListBox^ regressionAlgorithmListBox;
	private: System::Windows::Forms::Label^ regressionSelectAlgorithmLabel;
	private: System::Windows::Forms::Label^ regressionDataURLLabel;
	private: System::Windows::Forms::Button^ clusteringRuntButton;


	private: System::Windows::Forms::TextBox^ clusteringDataPathTextBox;

	private: System::Windows::Forms::ListBox^ clusteringAlgorithmListBox;
	private: System::Windows::Forms::Label^ clusteringSelectAlgorithmLabel;
	private: System::Windows::Forms::Label^ clusteringDataURLLabel;
	private: System::Windows::Forms::DataGridView^ classificationDataGridView;
	private: System::Windows::Forms::DataGridView^ regressionDataGridView;
	private: System::Windows::Forms::DataGridView^ clusteringDataGridView;
	private: System::Windows::Forms::DataGridView^ testCMDataGridView;







	private: System::Windows::Forms::Label^ testConfusionMatrixLabel;
	private: System::Windows::Forms::DataGridView^ testEvaluationDataGridView;


	private: System::Windows::Forms::Label^ testAccuracyLabel;
	private: System::Windows::Forms::TextBox^ testAccuracyTextBox;



	private: System::Windows::Forms::TextBox^ maeTestTextBox;

	private: System::Windows::Forms::TextBox^ rmseTestTextBox;

	private: System::Windows::Forms::Label^ maeTestLabel;

	private: System::Windows::Forms::Label^ rmseTestLabel;
	private: System::Windows::Forms::Label^ testEvaluationLabel;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ clusteringChart;





	private: System::Windows::Forms::TextBox^ silhouetteScoreTextBox;
	private: System::Windows::Forms::Label^ silhouetteScoreLabel;
	private: System::Windows::Forms::Label^ daviesBouldinIndexLabel;


	private: System::Windows::Forms::TextBox^ daviesBouldinIndexTextBox;
	private: System::Windows::Forms::Label^ rSquaredTestLabel;
	private: System::Windows::Forms::TextBox^ rSquaredTestTextBox;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ testRegressionChart;



	private: System::Windows::Forms::Button^ regressionBrowseButton;
	private: System::Windows::Forms::OpenFileDialog^ dataOpenFileDialog;


	private: System::Windows::Forms::TextBox^ rSquaredTrainTextBox;

	private: System::Windows::Forms::TextBox^ rmseTrainTextBox;

	private: System::Windows::Forms::TextBox^ maeTrainTextBox;
	private: System::Windows::Forms::TextBox^ regressionTraningSetTextBox;
	private: System::Windows::Forms::TextBox^ regressionTestSetTextBox;


	private: System::Windows::Forms::Label^ rSquaredTrainLabel;
	private: System::Windows::Forms::Label^ maeTrainLabel;
	private: System::Windows::Forms::Label^ rmseTrainLabel;
private: System::Windows::Forms::TableLayoutPanel^ regressionTrainingTableLayoutPanel;
private: System::Windows::Forms::Label^ regressionTestSetLabel;


private: System::Windows::Forms::Label^ regressionTrainingSetLabel;

	private: System::Windows::Forms::Label^ testSetEvaluationLabel;
	private: System::Windows::Forms::Label^ trainingSetEvaluationLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ trainingRegressionChart;
private: System::Windows::Forms::DataGridView^ trainingEvaluationDataGridView;

private: System::Windows::Forms::Label^ trainingEvaluationLabel;
private: System::Windows::Forms::DataGridView^ trainingCMDataGridView;
private: System::Windows::Forms::Label^ trainingConfusionMatrixLabel;
private: System::Windows::Forms::TextBox^ trainingAccuracyTextBox;
private: System::Windows::Forms::Label^ trainingAccuracyLabel;
private: System::Windows::Forms::Label^ classificationTrainingSetEvaluationLabel;
private: System::Windows::Forms::Label^ classificationTestSetEvaluationLabel;
private: System::Windows::Forms::TableLayoutPanel^ regressionTestTableLayoutPanel;
private: System::Windows::Forms::TableLayoutPanel^ regressionPercentageTableLayoutPanel;
private: System::Windows::Forms::Button^ classificationBrowseButton;
private: System::Windows::Forms::Button^ clusteringBrowseButton;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TableLayoutPanel^ clusteringEvaluationTableLayoutPanel;
private: System::Windows::Forms::TextBox^ classificationTestSetTextBox;

private: System::Windows::Forms::TextBox^ classificationTraningSetTextBox;

private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ classificationTestSetLabel;

private: System::Windows::Forms::Label^ classificationTrainingSetLabel;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;





























	protected:




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->mainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->classificationTabPage = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->classificationTrainingSetLabel = (gcnew System::Windows::Forms::Label());
			this->classificationTraningSetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->classificationTestSetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->classificationTestSetLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->classificationBrowseButton = (gcnew System::Windows::Forms::Button());
			this->classificationTestSetEvaluationLabel = (gcnew System::Windows::Forms::Label());
			this->classificationTrainingSetEvaluationLabel = (gcnew System::Windows::Forms::Label());
			this->trainingAccuracyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->trainingAccuracyLabel = (gcnew System::Windows::Forms::Label());
			this->trainingConfusionMatrixLabel = (gcnew System::Windows::Forms::Label());
			this->trainingCMDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->trainingEvaluationLabel = (gcnew System::Windows::Forms::Label());
			this->trainingEvaluationDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->testEvaluationLabel = (gcnew System::Windows::Forms::Label());
			this->testEvaluationDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->testConfusionMatrixLabel = (gcnew System::Windows::Forms::Label());
			this->testCMDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->testAccuracyLabel = (gcnew System::Windows::Forms::Label());
			this->testAccuracyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->classificationDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->calassificationRunButton = (gcnew System::Windows::Forms::Button());
			this->classificationDataPathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->classificationAlgorithmListBox = (gcnew System::Windows::Forms::ListBox());
			this->calssificationSelectAlgorithmLabel = (gcnew System::Windows::Forms::Label());
			this->classificationDataURLLabel = (gcnew System::Windows::Forms::Label());
			this->regressionTabPage = (gcnew System::Windows::Forms::TabPage());
			this->regressionPercentageTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->regressionTestSetLabel = (gcnew System::Windows::Forms::Label());
			this->regressionTrainingSetLabel = (gcnew System::Windows::Forms::Label());
			this->regressionTestSetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->regressionTraningSetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->regressionTestTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->rmseTestLabel = (gcnew System::Windows::Forms::Label());
			this->maeTestLabel = (gcnew System::Windows::Forms::Label());
			this->rSquaredTestLabel = (gcnew System::Windows::Forms::Label());
			this->rmseTestTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maeTestTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rSquaredTestTextBox = (gcnew System::Windows::Forms::TextBox());
			this->trainingRegressionChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->testSetEvaluationLabel = (gcnew System::Windows::Forms::Label());
			this->trainingSetEvaluationLabel = (gcnew System::Windows::Forms::Label());
			this->regressionTrainingTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->rmseTrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rSquaredTrainLabel = (gcnew System::Windows::Forms::Label());
			this->rmseTrainLabel = (gcnew System::Windows::Forms::Label());
			this->rSquaredTrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maeTrainLabel = (gcnew System::Windows::Forms::Label());
			this->maeTrainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->regressionBrowseButton = (gcnew System::Windows::Forms::Button());
			this->testRegressionChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->regressionDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->regressionRuntButton = (gcnew System::Windows::Forms::Button());
			this->regressionDataPathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->regressionAlgorithmListBox = (gcnew System::Windows::Forms::ListBox());
			this->regressionSelectAlgorithmLabel = (gcnew System::Windows::Forms::Label());
			this->regressionDataURLLabel = (gcnew System::Windows::Forms::Label());
			this->clusteringTabPage = (gcnew System::Windows::Forms::TabPage());
			this->clusteringEvaluationTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->daviesBouldinIndexLabel = (gcnew System::Windows::Forms::Label());
			this->silhouetteScoreLabel = (gcnew System::Windows::Forms::Label());
			this->daviesBouldinIndexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->silhouetteScoreTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->clusteringBrowseButton = (gcnew System::Windows::Forms::Button());
			this->clusteringChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->clusteringDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->clusteringRuntButton = (gcnew System::Windows::Forms::Button());
			this->clusteringDataPathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->clusteringAlgorithmListBox = (gcnew System::Windows::Forms::ListBox());
			this->clusteringSelectAlgorithmLabel = (gcnew System::Windows::Forms::Label());
			this->clusteringDataURLLabel = (gcnew System::Windows::Forms::Label());
			this->dataOpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->mainTabControl->SuspendLayout();
			this->classificationTabPage->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingCMDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingEvaluationDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testEvaluationDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testCMDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classificationDataGridView))->BeginInit();
			this->regressionTabPage->SuspendLayout();
			this->regressionPercentageTableLayoutPanel->SuspendLayout();
			this->regressionTestTableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingRegressionChart))->BeginInit();
			this->regressionTrainingTableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testRegressionChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->regressionDataGridView))->BeginInit();
			this->clusteringTabPage->SuspendLayout();
			this->clusteringEvaluationTableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clusteringChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clusteringDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// mainTabControl
			// 
			this->mainTabControl->Controls->Add(this->classificationTabPage);
			this->mainTabControl->Controls->Add(this->regressionTabPage);
			this->mainTabControl->Controls->Add(this->clusteringTabPage);
			this->mainTabControl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainTabControl->ItemSize = System::Drawing::Size(100, 30);
			this->mainTabControl->Location = System::Drawing::Point(2, 1);
			this->mainTabControl->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mainTabControl->Name = L"mainTabControl";
			this->mainTabControl->SelectedIndex = 0;
			this->mainTabControl->Size = System::Drawing::Size(2550, 1565);
			this->mainTabControl->TabIndex = 0;
			// 
			// classificationTabPage
			// 
			this->classificationTabPage->BackColor = System::Drawing::Color::Gainsboro;
			this->classificationTabPage->Controls->Add(this->tableLayoutPanel1);
			this->classificationTabPage->Controls->Add(this->label3);
			this->classificationTabPage->Controls->Add(this->classificationBrowseButton);
			this->classificationTabPage->Controls->Add(this->classificationTestSetEvaluationLabel);
			this->classificationTabPage->Controls->Add(this->classificationTrainingSetEvaluationLabel);
			this->classificationTabPage->Controls->Add(this->trainingAccuracyTextBox);
			this->classificationTabPage->Controls->Add(this->trainingAccuracyLabel);
			this->classificationTabPage->Controls->Add(this->trainingConfusionMatrixLabel);
			this->classificationTabPage->Controls->Add(this->trainingCMDataGridView);
			this->classificationTabPage->Controls->Add(this->trainingEvaluationLabel);
			this->classificationTabPage->Controls->Add(this->trainingEvaluationDataGridView);
			this->classificationTabPage->Controls->Add(this->testEvaluationLabel);
			this->classificationTabPage->Controls->Add(this->testEvaluationDataGridView);
			this->classificationTabPage->Controls->Add(this->testConfusionMatrixLabel);
			this->classificationTabPage->Controls->Add(this->testCMDataGridView);
			this->classificationTabPage->Controls->Add(this->testAccuracyLabel);
			this->classificationTabPage->Controls->Add(this->testAccuracyTextBox);
			this->classificationTabPage->Controls->Add(this->classificationDataGridView);
			this->classificationTabPage->Controls->Add(this->calassificationRunButton);
			this->classificationTabPage->Controls->Add(this->classificationDataPathTextBox);
			this->classificationTabPage->Controls->Add(this->classificationAlgorithmListBox);
			this->classificationTabPage->Controls->Add(this->calssificationSelectAlgorithmLabel);
			this->classificationTabPage->Controls->Add(this->classificationDataURLLabel);
			this->classificationTabPage->Location = System::Drawing::Point(4, 34);
			this->classificationTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->classificationTabPage->Name = L"classificationTabPage";
			this->classificationTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->classificationTabPage->Size = System::Drawing::Size(2542, 1527);
			this->classificationTabPage->TabIndex = 0;
			this->classificationTabPage->Text = L"Classification";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				54.3956F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				45.6044F)));
			this->tableLayoutPanel1->Controls->Add(this->classificationTrainingSetLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->classificationTraningSetTextBox, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->classificationTestSetTextBox, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->classificationTestSetLabel, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(916, 157);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(182, 55);
			this->tableLayoutPanel1->TabIndex = 39;
			// 
			// classificationTrainingSetLabel
			// 
			this->classificationTrainingSetLabel->AutoSize = true;
			this->classificationTrainingSetLabel->Location = System::Drawing::Point(3, 0);
			this->classificationTrainingSetLabel->Name = L"classificationTrainingSetLabel";
			this->classificationTrainingSetLabel->Size = System::Drawing::Size(85, 17);
			this->classificationTrainingSetLabel->TabIndex = 37;
			this->classificationTrainingSetLabel->Text = L"Training Set";
			// 
			// classificationTraningSetTextBox
			// 
			this->classificationTraningSetTextBox->Location = System::Drawing::Point(3, 30);
			this->classificationTraningSetTextBox->Name = L"classificationTraningSetTextBox";
			this->classificationTraningSetTextBox->Size = System::Drawing::Size(92, 23);
			this->classificationTraningSetTextBox->TabIndex = 35;
			// 
			// classificationTestSetTextBox
			// 
			this->classificationTestSetTextBox->Location = System::Drawing::Point(101, 30);
			this->classificationTestSetTextBox->Name = L"classificationTestSetTextBox";
			this->classificationTestSetTextBox->Size = System::Drawing::Size(77, 23);
			this->classificationTestSetTextBox->TabIndex = 36;
			// 
			// classificationTestSetLabel
			// 
			this->classificationTestSetLabel->AutoSize = true;
			this->classificationTestSetLabel->Location = System::Drawing::Point(101, 0);
			this->classificationTestSetLabel->Name = L"classificationTestSetLabel";
			this->classificationTestSetLabel->Size = System::Drawing::Size(61, 17);
			this->classificationTestSetLabel->TabIndex = 38;
			this->classificationTestSetLabel->Text = L"Test Set";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(780, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 18);
			this->label3->TabIndex = 34;
			this->label3->Text = L"Insert Percentage:";
			// 
			// classificationBrowseButton
			// 
			this->classificationBrowseButton->Location = System::Drawing::Point(740, 53);
			this->classificationBrowseButton->Name = L"classificationBrowseButton";
			this->classificationBrowseButton->Size = System::Drawing::Size(63, 39);
			this->classificationBrowseButton->TabIndex = 33;
			this->classificationBrowseButton->Text = L"Browse";
			this->classificationBrowseButton->UseVisualStyleBackColor = true;
			this->classificationBrowseButton->Click += gcnew System::EventHandler(this, &MainForm::classificationBrowseButton_Click);
			// 
			// classificationTestSetEvaluationLabel
			// 
			this->classificationTestSetEvaluationLabel->AutoSize = true;
			this->classificationTestSetEvaluationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->classificationTestSetEvaluationLabel->Location = System::Drawing::Point(19, 691);
			this->classificationTestSetEvaluationLabel->Name = L"classificationTestSetEvaluationLabel";
			this->classificationTestSetEvaluationLabel->Size = System::Drawing::Size(291, 18);
			this->classificationTestSetEvaluationLabel->TabIndex = 32;
			this->classificationTestSetEvaluationLabel->Text = L"Test Set Evaluation and Visualisation:";
			// 
			// classificationTrainingSetEvaluationLabel
			// 
			this->classificationTrainingSetEvaluationLabel->AutoSize = true;
			this->classificationTrainingSetEvaluationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->classificationTrainingSetEvaluationLabel->Location = System::Drawing::Point(13, 416);
			this->classificationTrainingSetEvaluationLabel->Name = L"classificationTrainingSetEvaluationLabel";
			this->classificationTrainingSetEvaluationLabel->Size = System::Drawing::Size(318, 18);
			this->classificationTrainingSetEvaluationLabel->TabIndex = 31;
			this->classificationTrainingSetEvaluationLabel->Text = L"Training Set Evaluation and Visualisation:";
			// 
			// trainingAccuracyTextBox
			// 
			this->trainingAccuracyTextBox->Location = System::Drawing::Point(53, 559);
			this->trainingAccuracyTextBox->Name = L"trainingAccuracyTextBox";
			this->trainingAccuracyTextBox->Size = System::Drawing::Size(100, 23);
			this->trainingAccuracyTextBox->TabIndex = 30;
			// 
			// trainingAccuracyLabel
			// 
			this->trainingAccuracyLabel->AutoSize = true;
			this->trainingAccuracyLabel->Location = System::Drawing::Point(74, 535);
			this->trainingAccuracyLabel->Name = L"trainingAccuracyLabel";
			this->trainingAccuracyLabel->Size = System::Drawing::Size(66, 17);
			this->trainingAccuracyLabel->TabIndex = 29;
			this->trainingAccuracyLabel->Text = L"Accuracy";
			// 
			// trainingConfusionMatrixLabel
			// 
			this->trainingConfusionMatrixLabel->AutoSize = true;
			this->trainingConfusionMatrixLabel->Location = System::Drawing::Point(349, 451);
			this->trainingConfusionMatrixLabel->Name = L"trainingConfusionMatrixLabel";
			this->trainingConfusionMatrixLabel->Size = System::Drawing::Size(112, 17);
			this->trainingConfusionMatrixLabel->TabIndex = 28;
			this->trainingConfusionMatrixLabel->Text = L"Confusion Matrix";
			// 
			// trainingCMDataGridView
			// 
			this->trainingCMDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->trainingCMDataGridView->Location = System::Drawing::Point(195, 487);
			this->trainingCMDataGridView->Name = L"trainingCMDataGridView";
			this->trainingCMDataGridView->RowHeadersWidth = 51;
			this->trainingCMDataGridView->Size = System::Drawing::Size(362, 146);
			this->trainingCMDataGridView->TabIndex = 27;
			// 
			// trainingEvaluationLabel
			// 
			this->trainingEvaluationLabel->AutoSize = true;
			this->trainingEvaluationLabel->Location = System::Drawing::Point(714, 451);
			this->trainingEvaluationLabel->Name = L"trainingEvaluationLabel";
			this->trainingEvaluationLabel->Size = System::Drawing::Size(202, 17);
			this->trainingEvaluationLabel->TabIndex = 26;
			this->trainingEvaluationLabel->Text = L"Recall, Precision and F1 Score";
			// 
			// trainingEvaluationDataGridView
			// 
			this->trainingEvaluationDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->trainingEvaluationDataGridView->Location = System::Drawing::Point(581, 487);
			this->trainingEvaluationDataGridView->Name = L"trainingEvaluationDataGridView";
			this->trainingEvaluationDataGridView->RowHeadersWidth = 51;
			this->trainingEvaluationDataGridView->Size = System::Drawing::Size(459, 145);
			this->trainingEvaluationDataGridView->TabIndex = 25;
			// 
			// testEvaluationLabel
			// 
			this->testEvaluationLabel->AutoSize = true;
			this->testEvaluationLabel->Location = System::Drawing::Point(682, 725);
			this->testEvaluationLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->testEvaluationLabel->Name = L"testEvaluationLabel";
			this->testEvaluationLabel->Size = System::Drawing::Size(202, 17);
			this->testEvaluationLabel->TabIndex = 24;
			this->testEvaluationLabel->Text = L"Recall, Precision and F1 Score";
			// 
			// testEvaluationDataGridView
			// 
			this->testEvaluationDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->testEvaluationDataGridView->Location = System::Drawing::Point(578, 752);
			this->testEvaluationDataGridView->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->testEvaluationDataGridView->Name = L"testEvaluationDataGridView";
			this->testEvaluationDataGridView->RowHeadersWidth = 51;
			this->testEvaluationDataGridView->RowTemplate->Height = 24;
			this->testEvaluationDataGridView->Size = System::Drawing::Size(468, 130);
			this->testEvaluationDataGridView->TabIndex = 23;
			// 
			// testConfusionMatrixLabel
			// 
			this->testConfusionMatrixLabel->AutoSize = true;
			this->testConfusionMatrixLabel->Location = System::Drawing::Point(314, 725);
			this->testConfusionMatrixLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->testConfusionMatrixLabel->Name = L"testConfusionMatrixLabel";
			this->testConfusionMatrixLabel->Size = System::Drawing::Size(112, 17);
			this->testConfusionMatrixLabel->TabIndex = 22;
			this->testConfusionMatrixLabel->Text = L"Confusion Matrix";
			// 
			// testCMDataGridView
			// 
			this->testCMDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->testCMDataGridView->Location = System::Drawing::Point(191, 752);
			this->testCMDataGridView->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->testCMDataGridView->Name = L"testCMDataGridView";
			this->testCMDataGridView->RowHeadersWidth = 51;
			this->testCMDataGridView->RowTemplate->Height = 24;
			this->testCMDataGridView->Size = System::Drawing::Size(364, 130);
			this->testCMDataGridView->TabIndex = 21;
			// 
			// testAccuracyLabel
			// 
			this->testAccuracyLabel->AutoSize = true;
			this->testAccuracyLabel->Location = System::Drawing::Point(77, 785);
			this->testAccuracyLabel->Name = L"testAccuracyLabel";
			this->testAccuracyLabel->Size = System::Drawing::Size(66, 17);
			this->testAccuracyLabel->TabIndex = 10;
			this->testAccuracyLabel->Text = L"Accuracy";
			// 
			// testAccuracyTextBox
			// 
			this->testAccuracyTextBox->Location = System::Drawing::Point(67, 805);
			this->testAccuracyTextBox->Name = L"testAccuracyTextBox";
			this->testAccuracyTextBox->Size = System::Drawing::Size(80, 23);
			this->testAccuracyTextBox->TabIndex = 9;
			// 
			// classificationDataGridView
			// 
			this->classificationDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->classificationDataGridView->Location = System::Drawing::Point(99, 80);
			this->classificationDataGridView->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->classificationDataGridView->Name = L"classificationDataGridView";
			this->classificationDataGridView->RowHeadersWidth = 51;
			this->classificationDataGridView->RowTemplate->Height = 24;
			this->classificationDataGridView->Size = System::Drawing::Size(585, 279);
			this->classificationDataGridView->TabIndex = 6;
			// 
			// calassificationRunButton
			// 
			this->calassificationRunButton->Location = System::Drawing::Point(1175, 295);
			this->calassificationRunButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->calassificationRunButton->Name = L"calassificationRunButton";
			this->calassificationRunButton->Size = System::Drawing::Size(67, 42);
			this->calassificationRunButton->TabIndex = 5;
			this->calassificationRunButton->Text = L"Run";
			this->calassificationRunButton->UseVisualStyleBackColor = true;
			this->calassificationRunButton->Click += gcnew System::EventHandler(this, &MainForm::calassificationRunButton_Click);
			// 
			// classificationDataPathTextBox
			// 
			this->classificationDataPathTextBox->Location = System::Drawing::Point(99, 53);
			this->classificationDataPathTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->classificationDataPathTextBox->Name = L"classificationDataPathTextBox";
			this->classificationDataPathTextBox->Size = System::Drawing::Size(587, 23);
			this->classificationDataPathTextBox->TabIndex = 3;
			// 
			// classificationAlgorithmListBox
			// 
			this->classificationAlgorithmListBox->FormattingEnabled = true;
			this->classificationAlgorithmListBox->ItemHeight = 17;
			this->classificationAlgorithmListBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"KNN Classification", L"Decision Tree Classification",
					L"Logistic Regression (Classification)"
			});
			this->classificationAlgorithmListBox->Location = System::Drawing::Point(916, 282);
			this->classificationAlgorithmListBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->classificationAlgorithmListBox->Name = L"classificationAlgorithmListBox";
			this->classificationAlgorithmListBox->Size = System::Drawing::Size(237, 55);
			this->classificationAlgorithmListBox->TabIndex = 2;
			this->classificationAlgorithmListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::classificationAlgorithmListBox_SelectedIndexChanged);
			// 
			// calssificationSelectAlgorithmLabel
			// 
			this->calssificationSelectAlgorithmLabel->AutoSize = true;
			this->calssificationSelectAlgorithmLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->calssificationSelectAlgorithmLabel->Location = System::Drawing::Point(780, 256);
			this->calssificationSelectAlgorithmLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->calssificationSelectAlgorithmLabel->Name = L"calssificationSelectAlgorithmLabel";
			this->calssificationSelectAlgorithmLabel->Size = System::Drawing::Size(136, 18);
			this->calssificationSelectAlgorithmLabel->TabIndex = 1;
			this->calssificationSelectAlgorithmLabel->Text = L"Select Algorithm:";
			// 
			// classificationDataURLLabel
			// 
			this->classificationDataURLLabel->AutoSize = true;
			this->classificationDataURLLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->classificationDataURLLabel->Location = System::Drawing::Point(19, 26);
			this->classificationDataURLLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->classificationDataURLLabel->Name = L"classificationDataURLLabel";
			this->classificationDataURLLabel->Size = System::Drawing::Size(87, 18);
			this->classificationDataURLLabel->TabIndex = 0;
			this->classificationDataURLLabel->Text = L"Data Path:";
			// 
			// regressionTabPage
			// 
			this->regressionTabPage->BackColor = System::Drawing::Color::Gainsboro;
			this->regressionTabPage->Controls->Add(this->regressionPercentageTableLayoutPanel);
			this->regressionTabPage->Controls->Add(this->regressionTestTableLayoutPanel);
			this->regressionTabPage->Controls->Add(this->trainingRegressionChart);
			this->regressionTabPage->Controls->Add(this->label1);
			this->regressionTabPage->Controls->Add(this->testSetEvaluationLabel);
			this->regressionTabPage->Controls->Add(this->trainingSetEvaluationLabel);
			this->regressionTabPage->Controls->Add(this->regressionTrainingTableLayoutPanel);
			this->regressionTabPage->Controls->Add(this->regressionBrowseButton);
			this->regressionTabPage->Controls->Add(this->testRegressionChart);
			this->regressionTabPage->Controls->Add(this->regressionDataGridView);
			this->regressionTabPage->Controls->Add(this->regressionRuntButton);
			this->regressionTabPage->Controls->Add(this->regressionDataPathTextBox);
			this->regressionTabPage->Controls->Add(this->regressionAlgorithmListBox);
			this->regressionTabPage->Controls->Add(this->regressionSelectAlgorithmLabel);
			this->regressionTabPage->Controls->Add(this->regressionDataURLLabel);
			this->regressionTabPage->Location = System::Drawing::Point(4, 34);
			this->regressionTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->regressionTabPage->Name = L"regressionTabPage";
			this->regressionTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->regressionTabPage->Size = System::Drawing::Size(2542, 1527);
			this->regressionTabPage->TabIndex = 1;
			this->regressionTabPage->Text = L"Regression";
			// 
			// regressionPercentageTableLayoutPanel
			// 
			this->regressionPercentageTableLayoutPanel->ColumnCount = 2;
			this->regressionPercentageTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				55.03356F)));
			this->regressionPercentageTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				44.96644F)));
			this->regressionPercentageTableLayoutPanel->Controls->Add(this->regressionTestSetLabel, 1, 0);
			this->regressionPercentageTableLayoutPanel->Controls->Add(this->regressionTrainingSetLabel, 0, 0);
			this->regressionPercentageTableLayoutPanel->Controls->Add(this->regressionTestSetTextBox, 1, 1);
			this->regressionPercentageTableLayoutPanel->Controls->Add(this->regressionTraningSetTextBox, 0, 1);
			this->regressionPercentageTableLayoutPanel->Location = System::Drawing::Point(942, 157);
			this->regressionPercentageTableLayoutPanel->Name = L"regressionPercentageTableLayoutPanel";
			this->regressionPercentageTableLayoutPanel->RowCount = 2;
			this->regressionPercentageTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50.81967F)));
			this->regressionPercentageTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				49.18033F)));
			this->regressionPercentageTableLayoutPanel->Size = System::Drawing::Size(174, 58);
			this->regressionPercentageTableLayoutPanel->TabIndex = 37;
			// 
			// regressionTestSetLabel
			// 
			this->regressionTestSetLabel->AutoSize = true;
			this->regressionTestSetLabel->Location = System::Drawing::Point(98, 0);
			this->regressionTestSetLabel->Name = L"regressionTestSetLabel";
			this->regressionTestSetLabel->Size = System::Drawing::Size(61, 17);
			this->regressionTestSetLabel->TabIndex = 31;
			this->regressionTestSetLabel->Text = L"Test Set";
			// 
			// regressionTrainingSetLabel
			// 
			this->regressionTrainingSetLabel->AutoSize = true;
			this->regressionTrainingSetLabel->Location = System::Drawing::Point(3, 0);
			this->regressionTrainingSetLabel->Name = L"regressionTrainingSetLabel";
			this->regressionTrainingSetLabel->Size = System::Drawing::Size(85, 17);
			this->regressionTrainingSetLabel->TabIndex = 30;
			this->regressionTrainingSetLabel->Text = L"Training Set";
			// 
			// regressionTestSetTextBox
			// 
			this->regressionTestSetTextBox->Location = System::Drawing::Point(98, 32);
			this->regressionTestSetTextBox->Name = L"regressionTestSetTextBox";
			this->regressionTestSetTextBox->Size = System::Drawing::Size(70, 23);
			this->regressionTestSetTextBox->TabIndex = 25;
			// 
			// regressionTraningSetTextBox
			// 
			this->regressionTraningSetTextBox->Location = System::Drawing::Point(3, 32);
			this->regressionTraningSetTextBox->Name = L"regressionTraningSetTextBox";
			this->regressionTraningSetTextBox->Size = System::Drawing::Size(85, 23);
			this->regressionTraningSetTextBox->TabIndex = 24;
			// 
			// regressionTestTableLayoutPanel
			// 
			this->regressionTestTableLayoutPanel->ColumnCount = 2;
			this->regressionTestTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				76.14679F)));
			this->regressionTestTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				23.85321F)));
			this->regressionTestTableLayoutPanel->Controls->Add(this->rmseTestLabel, 0, 0);
			this->regressionTestTableLayoutPanel->Controls->Add(this->maeTestLabel, 0, 1);
			this->regressionTestTableLayoutPanel->Controls->Add(this->rSquaredTestLabel, 0, 2);
			this->regressionTestTableLayoutPanel->Controls->Add(this->rmseTestTextBox, 1, 0);
			this->regressionTestTableLayoutPanel->Controls->Add(this->maeTestTextBox, 1, 1);
			this->regressionTestTableLayoutPanel->Controls->Add(this->rSquaredTestTextBox, 1, 2);
			this->regressionTestTableLayoutPanel->Location = System::Drawing::Point(797, 433);
			this->regressionTestTableLayoutPanel->Name = L"regressionTestTableLayoutPanel";
			this->regressionTestTableLayoutPanel->RowCount = 3;
			this->regressionTestTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->regressionTestTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->regressionTestTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				34)));
			this->regressionTestTableLayoutPanel->Size = System::Drawing::Size(305, 117);
			this->regressionTestTableLayoutPanel->TabIndex = 36;
			// 
			// rmseTestLabel
			// 
			this->rmseTestLabel->AutoSize = true;
			this->rmseTestLabel->Location = System::Drawing::Point(2, 0);
			this->rmseTestLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rmseTestLabel->Name = L"rmseTestLabel";
			this->rmseTestLabel->Size = System::Drawing::Size(220, 17);
			this->rmseTestLabel->TabIndex = 13;
			this->rmseTestLabel->Text = L"Root Mean Squared Error(RMSE)";
			// 
			// maeTestLabel
			// 
			this->maeTestLabel->AutoSize = true;
			this->maeTestLabel->Location = System::Drawing::Point(2, 41);
			this->maeTestLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->maeTestLabel->Name = L"maeTestLabel";
			this->maeTestLabel->Size = System::Drawing::Size(181, 17);
			this->maeTestLabel->TabIndex = 14;
			this->maeTestLabel->Text = L"Mean Absolute Error (MAE)";
			// 
			// rSquaredTestLabel
			// 
			this->rSquaredTestLabel->AutoSize = true;
			this->rSquaredTestLabel->Location = System::Drawing::Point(2, 82);
			this->rSquaredTestLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rSquaredTestLabel->Name = L"rSquaredTestLabel";
			this->rSquaredTestLabel->Size = System::Drawing::Size(76, 17);
			this->rSquaredTestLabel->TabIndex = 17;
			this->rSquaredTestLabel->Text = L"R Squared";
			// 
			// rmseTestTextBox
			// 
			this->rmseTestTextBox->Location = System::Drawing::Point(234, 2);
			this->rmseTestTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rmseTestTextBox->Name = L"rmseTestTextBox";
			this->rmseTestTextBox->Size = System::Drawing::Size(69, 23);
			this->rmseTestTextBox->TabIndex = 15;
			// 
			// maeTestTextBox
			// 
			this->maeTestTextBox->Location = System::Drawing::Point(234, 43);
			this->maeTestTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->maeTestTextBox->Name = L"maeTestTextBox";
			this->maeTestTextBox->Size = System::Drawing::Size(69, 23);
			this->maeTestTextBox->TabIndex = 16;
			// 
			// rSquaredTestTextBox
			// 
			this->rSquaredTestTextBox->Location = System::Drawing::Point(234, 84);
			this->rSquaredTestTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rSquaredTestTextBox->Name = L"rSquaredTestTextBox";
			this->rSquaredTestTextBox->Size = System::Drawing::Size(69, 23);
			this->rSquaredTestTextBox->TabIndex = 18;
			// 
			// trainingRegressionChart
			// 
			chartArea4->Name = L"ChartArea1";
			this->trainingRegressionChart->ChartAreas->Add(chartArea4);
			legend4->Enabled = false;
			legend4->Name = L"Legend1";
			this->trainingRegressionChart->Legends->Add(legend4);
			this->trainingRegressionChart->Location = System::Drawing::Point(362, 430);
			this->trainingRegressionChart->Name = L"trainingRegressionChart";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->trainingRegressionChart->Series->Add(series4);
			this->trainingRegressionChart->Size = System::Drawing::Size(334, 273);
			this->trainingRegressionChart->TabIndex = 35;
			this->trainingRegressionChart->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(807, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 18);
			this->label1->TabIndex = 34;
			this->label1->Text = L"Insert Percentage:";
			// 
			// testSetEvaluationLabel
			// 
			this->testSetEvaluationLabel->AutoSize = true;
			this->testSetEvaluationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->testSetEvaluationLabel->Location = System::Drawing::Point(794, 399);
			this->testSetEvaluationLabel->Name = L"testSetEvaluationLabel";
			this->testSetEvaluationLabel->Size = System::Drawing::Size(291, 18);
			this->testSetEvaluationLabel->TabIndex = 33;
			this->testSetEvaluationLabel->Text = L"Test Set Evaluation and Visualisation:";
			// 
			// trainingSetEvaluationLabel
			// 
			this->trainingSetEvaluationLabel->AutoSize = true;
			this->trainingSetEvaluationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->trainingSetEvaluationLabel->Location = System::Drawing::Point(25, 399);
			this->trainingSetEvaluationLabel->Name = L"trainingSetEvaluationLabel";
			this->trainingSetEvaluationLabel->Size = System::Drawing::Size(318, 18);
			this->trainingSetEvaluationLabel->TabIndex = 32;
			this->trainingSetEvaluationLabel->Text = L"Training Set Evaluation and Visualisation:";
			// 
			// regressionTrainingTableLayoutPanel
			// 
			this->regressionTrainingTableLayoutPanel->ColumnCount = 2;
			this->regressionTrainingTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				74.69512F)));
			this->regressionTrainingTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.30488F)));
			this->regressionTrainingTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->regressionTrainingTableLayoutPanel->Controls->Add(this->rmseTrainTextBox, 1, 0);
			this->regressionTrainingTableLayoutPanel->Controls->Add(this->rSquaredTrainLabel, 0, 2);
			this->regressionTrainingTableLayoutPanel->Controls->Add(this->rmseTrainLabel, 0, 0);
			this->regressionTrainingTableLayoutPanel->Controls->Add(this->rSquaredTrainTextBox, 1, 2);
			this->regressionTrainingTableLayoutPanel->Controls->Add(this->maeTrainLabel, 0, 1);
			this->regressionTrainingTableLayoutPanel->Controls->Add(this->maeTrainTextBox, 1, 1);
			this->regressionTrainingTableLayoutPanel->Location = System::Drawing::Point(24, 430);
			this->regressionTrainingTableLayoutPanel->Name = L"regressionTrainingTableLayoutPanel";
			this->regressionTrainingTableLayoutPanel->RowCount = 3;
			this->regressionTrainingTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				47.05882F)));
			this->regressionTrainingTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				52.94118F)));
			this->regressionTrainingTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				31)));
			this->regressionTrainingTableLayoutPanel->Size = System::Drawing::Size(308, 120);
			this->regressionTrainingTableLayoutPanel->TabIndex = 29;
			// 
			// rmseTrainTextBox
			// 
			this->rmseTrainTextBox->Location = System::Drawing::Point(233, 3);
			this->rmseTrainTextBox->Name = L"rmseTrainTextBox";
			this->rmseTrainTextBox->Size = System::Drawing::Size(72, 23);
			this->rmseTrainTextBox->TabIndex = 22;
			// 
			// rSquaredTrainLabel
			// 
			this->rSquaredTrainLabel->AutoSize = true;
			this->rSquaredTrainLabel->Location = System::Drawing::Point(3, 88);
			this->rSquaredTrainLabel->Name = L"rSquaredTrainLabel";
			this->rSquaredTrainLabel->Size = System::Drawing::Size(76, 17);
			this->rSquaredTrainLabel->TabIndex = 28;
			this->rSquaredTrainLabel->Text = L"R Squared";
			// 
			// rmseTrainLabel
			// 
			this->rmseTrainLabel->AutoSize = true;
			this->rmseTrainLabel->Location = System::Drawing::Point(3, 0);
			this->rmseTrainLabel->Name = L"rmseTrainLabel";
			this->rmseTrainLabel->Size = System::Drawing::Size(220, 17);
			this->rmseTrainLabel->TabIndex = 26;
			this->rmseTrainLabel->Text = L"Root Mean Squared Error(RMSE)";
			// 
			// rSquaredTrainTextBox
			// 
			this->rSquaredTrainTextBox->Location = System::Drawing::Point(233, 91);
			this->rSquaredTrainTextBox->Name = L"rSquaredTrainTextBox";
			this->rSquaredTrainTextBox->Size = System::Drawing::Size(72, 23);
			this->rSquaredTrainTextBox->TabIndex = 23;
			// 
			// maeTrainLabel
			// 
			this->maeTrainLabel->AutoSize = true;
			this->maeTrainLabel->Location = System::Drawing::Point(3, 41);
			this->maeTrainLabel->Name = L"maeTrainLabel";
			this->maeTrainLabel->Size = System::Drawing::Size(181, 17);
			this->maeTrainLabel->TabIndex = 27;
			this->maeTrainLabel->Text = L"Mean Absolute Error (MAE)";
			// 
			// maeTrainTextBox
			// 
			this->maeTrainTextBox->Location = System::Drawing::Point(233, 44);
			this->maeTrainTextBox->Name = L"maeTrainTextBox";
			this->maeTrainTextBox->Size = System::Drawing::Size(72, 23);
			this->maeTrainTextBox->TabIndex = 21;
			// 
			// regressionBrowseButton
			// 
			this->regressionBrowseButton->Location = System::Drawing::Point(715, 53);
			this->regressionBrowseButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->regressionBrowseButton->Name = L"regressionBrowseButton";
			this->regressionBrowseButton->Size = System::Drawing::Size(65, 39);
			this->regressionBrowseButton->TabIndex = 20;
			this->regressionBrowseButton->Text = L"Browse";
			this->regressionBrowseButton->UseVisualStyleBackColor = true;
			this->regressionBrowseButton->Click += gcnew System::EventHandler(this, &MainForm::regressionBrowseButton_Click);
			// 
			// testRegressionChart
			// 
			chartArea5->Name = L"ChartArea1";
			this->testRegressionChart->ChartAreas->Add(chartArea5);
			legend5->Enabled = false;
			legend5->Name = L"Legend1";
			this->testRegressionChart->Legends->Add(legend5);
			this->testRegressionChart->Location = System::Drawing::Point(1134, 433);
			this->testRegressionChart->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->testRegressionChart->Name = L"testRegressionChart";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series5->Legend = L"Legend1";
			series5->Name = L"Series1";
			this->testRegressionChart->Series->Add(series5);
			this->testRegressionChart->Size = System::Drawing::Size(334, 270);
			this->testRegressionChart->TabIndex = 19;
			this->testRegressionChart->Text = L"chart1";
			// 
			// regressionDataGridView
			// 
			this->regressionDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->regressionDataGridView->Location = System::Drawing::Point(99, 80);
			this->regressionDataGridView->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->regressionDataGridView->Name = L"regressionDataGridView";
			this->regressionDataGridView->RowHeadersWidth = 51;
			this->regressionDataGridView->RowTemplate->Height = 24;
			this->regressionDataGridView->Size = System::Drawing::Size(593, 260);
			this->regressionDataGridView->TabIndex = 12;
			// 
			// regressionRuntButton
			// 
			this->regressionRuntButton->Location = System::Drawing::Point(1176, 287);
			this->regressionRuntButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->regressionRuntButton->Name = L"regressionRuntButton";
			this->regressionRuntButton->Size = System::Drawing::Size(73, 38);
			this->regressionRuntButton->TabIndex = 11;
			this->regressionRuntButton->Text = L"Run";
			this->regressionRuntButton->UseVisualStyleBackColor = true;
			this->regressionRuntButton->Click += gcnew System::EventHandler(this, &MainForm::regressionRuntButton_Click);
			// 
			// regressionDataPathTextBox
			// 
			this->regressionDataPathTextBox->Location = System::Drawing::Point(99, 53);
			this->regressionDataPathTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->regressionDataPathTextBox->Name = L"regressionDataPathTextBox";
			this->regressionDataPathTextBox->Size = System::Drawing::Size(593, 23);
			this->regressionDataPathTextBox->TabIndex = 9;
			// 
			// regressionAlgorithmListBox
			// 
			this->regressionAlgorithmListBox->FormattingEnabled = true;
			this->regressionAlgorithmListBox->ItemHeight = 17;
			this->regressionAlgorithmListBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"KNN Regression", L"Linear Regression",
					L"Decision Tree Regression"
			});
			this->regressionAlgorithmListBox->Location = System::Drawing::Point(942, 287);
			this->regressionAlgorithmListBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->regressionAlgorithmListBox->Name = L"regressionAlgorithmListBox";
			this->regressionAlgorithmListBox->Size = System::Drawing::Size(203, 38);
			this->regressionAlgorithmListBox->TabIndex = 8;
			// 
			// regressionSelectAlgorithmLabel
			// 
			this->regressionSelectAlgorithmLabel->AutoSize = true;
			this->regressionSelectAlgorithmLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->regressionSelectAlgorithmLabel->Location = System::Drawing::Point(807, 261);
			this->regressionSelectAlgorithmLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->regressionSelectAlgorithmLabel->Name = L"regressionSelectAlgorithmLabel";
			this->regressionSelectAlgorithmLabel->Size = System::Drawing::Size(136, 18);
			this->regressionSelectAlgorithmLabel->TabIndex = 7;
			this->regressionSelectAlgorithmLabel->Text = L"Select Algorithm:";
			// 
			// regressionDataURLLabel
			// 
			this->regressionDataURLLabel->AutoSize = true;
			this->regressionDataURLLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->regressionDataURLLabel->Location = System::Drawing::Point(19, 26);
			this->regressionDataURLLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->regressionDataURLLabel->Name = L"regressionDataURLLabel";
			this->regressionDataURLLabel->Size = System::Drawing::Size(87, 18);
			this->regressionDataURLLabel->TabIndex = 6;
			this->regressionDataURLLabel->Text = L"Data Path:";
			// 
			// clusteringTabPage
			// 
			this->clusteringTabPage->BackColor = System::Drawing::Color::Gainsboro;
			this->clusteringTabPage->Controls->Add(this->clusteringEvaluationTableLayoutPanel);
			this->clusteringTabPage->Controls->Add(this->label2);
			this->clusteringTabPage->Controls->Add(this->clusteringBrowseButton);
			this->clusteringTabPage->Controls->Add(this->clusteringChart);
			this->clusteringTabPage->Controls->Add(this->clusteringDataGridView);
			this->clusteringTabPage->Controls->Add(this->clusteringRuntButton);
			this->clusteringTabPage->Controls->Add(this->clusteringDataPathTextBox);
			this->clusteringTabPage->Controls->Add(this->clusteringAlgorithmListBox);
			this->clusteringTabPage->Controls->Add(this->clusteringSelectAlgorithmLabel);
			this->clusteringTabPage->Controls->Add(this->clusteringDataURLLabel);
			this->clusteringTabPage->Location = System::Drawing::Point(4, 34);
			this->clusteringTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->clusteringTabPage->Name = L"clusteringTabPage";
			this->clusteringTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->clusteringTabPage->Size = System::Drawing::Size(2542, 1527);
			this->clusteringTabPage->TabIndex = 2;
			this->clusteringTabPage->Text = L"Clustering";
			// 
			// clusteringEvaluationTableLayoutPanel
			// 
			this->clusteringEvaluationTableLayoutPanel->ColumnCount = 2;
			this->clusteringEvaluationTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				69.96587F)));
			this->clusteringEvaluationTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30.03413F)));
			this->clusteringEvaluationTableLayoutPanel->Controls->Add(this->daviesBouldinIndexLabel, 0, 0);
			this->clusteringEvaluationTableLayoutPanel->Controls->Add(this->silhouetteScoreLabel, 0, 1);
			this->clusteringEvaluationTableLayoutPanel->Controls->Add(this->daviesBouldinIndexTextBox, 1, 0);
			this->clusteringEvaluationTableLayoutPanel->Controls->Add(this->silhouetteScoreTextBox, 1, 1);
			this->clusteringEvaluationTableLayoutPanel->Location = System::Drawing::Point(316, 438);
			this->clusteringEvaluationTableLayoutPanel->Name = L"clusteringEvaluationTableLayoutPanel";
			this->clusteringEvaluationTableLayoutPanel->RowCount = 2;
			this->clusteringEvaluationTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->clusteringEvaluationTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->clusteringEvaluationTableLayoutPanel->Size = System::Drawing::Size(216, 81);
			this->clusteringEvaluationTableLayoutPanel->TabIndex = 28;
			// 
			// daviesBouldinIndexLabel
			// 
			this->daviesBouldinIndexLabel->AutoSize = true;
			this->daviesBouldinIndexLabel->Location = System::Drawing::Point(3, 0);
			this->daviesBouldinIndexLabel->Name = L"daviesBouldinIndexLabel";
			this->daviesBouldinIndexLabel->Size = System::Drawing::Size(139, 17);
			this->daviesBouldinIndexLabel->TabIndex = 23;
			this->daviesBouldinIndexLabel->Text = L"Davies Bouldin Index";
			// 
			// silhouetteScoreLabel
			// 
			this->silhouetteScoreLabel->AutoSize = true;
			this->silhouetteScoreLabel->Location = System::Drawing::Point(3, 40);
			this->silhouetteScoreLabel->Name = L"silhouetteScoreLabel";
			this->silhouetteScoreLabel->Size = System::Drawing::Size(112, 17);
			this->silhouetteScoreLabel->TabIndex = 24;
			this->silhouetteScoreLabel->Text = L"Silhouette Score";
			// 
			// daviesBouldinIndexTextBox
			// 
			this->daviesBouldinIndexTextBox->Location = System::Drawing::Point(154, 3);
			this->daviesBouldinIndexTextBox->Name = L"daviesBouldinIndexTextBox";
			this->daviesBouldinIndexTextBox->Size = System::Drawing::Size(59, 23);
			this->daviesBouldinIndexTextBox->TabIndex = 22;
			// 
			// silhouetteScoreTextBox
			// 
			this->silhouetteScoreTextBox->Location = System::Drawing::Point(154, 43);
			this->silhouetteScoreTextBox->Name = L"silhouetteScoreTextBox";
			this->silhouetteScoreTextBox->Size = System::Drawing::Size(59, 23);
			this->silhouetteScoreTextBox->TabIndex = 25;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(20, 403);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(304, 18);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Clustering Evaluation and Visualisation:";
			// 
			// clusteringBrowseButton
			// 
			this->clusteringBrowseButton->Location = System::Drawing::Point(724, 53);
			this->clusteringBrowseButton->Name = L"clusteringBrowseButton";
			this->clusteringBrowseButton->Size = System::Drawing::Size(65, 35);
			this->clusteringBrowseButton->TabIndex = 26;
			this->clusteringBrowseButton->Text = L"Browse";
			this->clusteringBrowseButton->UseVisualStyleBackColor = true;
			this->clusteringBrowseButton->Click += gcnew System::EventHandler(this, &MainForm::clusteringBrowseButton_Click);
			// 
			// clusteringChart
			// 
			chartArea6->Name = L"ChartArea1";
			this->clusteringChart->ChartAreas->Add(chartArea6);
			legend6->Enabled = false;
			legend6->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend6->Name = L"Legend1";
			this->clusteringChart->Legends->Add(legend6);
			this->clusteringChart->Location = System::Drawing::Point(652, 438);
			this->clusteringChart->Name = L"clusteringChart";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series6->Legend = L"Legend1";
			series6->MarkerSize = 10;
			series6->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Star5;
			series6->Name = L"Series1";
			this->clusteringChart->Series->Add(series6);
			this->clusteringChart->Size = System::Drawing::Size(402, 400);
			this->clusteringChart->TabIndex = 21;
			this->clusteringChart->Text = L"chart1";
			// 
			// clusteringDataGridView
			// 
			this->clusteringDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->clusteringDataGridView->Location = System::Drawing::Point(99, 80);
			this->clusteringDataGridView->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->clusteringDataGridView->Name = L"clusteringDataGridView";
			this->clusteringDataGridView->RowHeadersWidth = 51;
			this->clusteringDataGridView->RowTemplate->Height = 24;
			this->clusteringDataGridView->Size = System::Drawing::Size(585, 260);
			this->clusteringDataGridView->TabIndex = 18;
			// 
			// clusteringRuntButton
			// 
			this->clusteringRuntButton->Location = System::Drawing::Point(1056, 170);
			this->clusteringRuntButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->clusteringRuntButton->Name = L"clusteringRuntButton";
			this->clusteringRuntButton->Size = System::Drawing::Size(58, 36);
			this->clusteringRuntButton->TabIndex = 17;
			this->clusteringRuntButton->Text = L"Run";
			this->clusteringRuntButton->UseVisualStyleBackColor = true;
			this->clusteringRuntButton->Click += gcnew System::EventHandler(this, &MainForm::clusteringRunButton_Click);
			// 
			// clusteringDataPathTextBox
			// 
			this->clusteringDataPathTextBox->Location = System::Drawing::Point(99, 53);
			this->clusteringDataPathTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->clusteringDataPathTextBox->Name = L"clusteringDataPathTextBox";
			this->clusteringDataPathTextBox->Size = System::Drawing::Size(585, 23);
			this->clusteringDataPathTextBox->TabIndex = 15;
			// 
			// clusteringAlgorithmListBox
			// 
			this->clusteringAlgorithmListBox->FormattingEnabled = true;
			this->clusteringAlgorithmListBox->ItemHeight = 17;
			this->clusteringAlgorithmListBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"K-means", L"Fuzzy c-means" });
			this->clusteringAlgorithmListBox->Location = System::Drawing::Point(901, 162);
			this->clusteringAlgorithmListBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->clusteringAlgorithmListBox->Name = L"clusteringAlgorithmListBox";
			this->clusteringAlgorithmListBox->Size = System::Drawing::Size(122, 38);
			this->clusteringAlgorithmListBox->TabIndex = 14;
			// 
			// clusteringSelectAlgorithmLabel
			// 
			this->clusteringSelectAlgorithmLabel->AutoSize = true;
			this->clusteringSelectAlgorithmLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->clusteringSelectAlgorithmLabel->Location = System::Drawing::Point(767, 142);
			this->clusteringSelectAlgorithmLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->clusteringSelectAlgorithmLabel->Name = L"clusteringSelectAlgorithmLabel";
			this->clusteringSelectAlgorithmLabel->Size = System::Drawing::Size(136, 18);
			this->clusteringSelectAlgorithmLabel->TabIndex = 13;
			this->clusteringSelectAlgorithmLabel->Text = L"Select Algorithm:";
			// 
			// clusteringDataURLLabel
			// 
			this->clusteringDataURLLabel->AutoSize = true;
			this->clusteringDataURLLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->clusteringDataURLLabel->Location = System::Drawing::Point(19, 26);
			this->clusteringDataURLLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->clusteringDataURLLabel->Name = L"clusteringDataURLLabel";
			this->clusteringDataURLLabel->Size = System::Drawing::Size(87, 18);
			this->clusteringDataURLLabel->TabIndex = 12;
			this->clusteringDataURLLabel->Text = L"Data Path:";
			// 
			// dataOpenFileDialog
			// 
			this->dataOpenFileDialog->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1719, 1061);
			this->Controls->Add(this->mainTabControl);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->mainTabControl->ResumeLayout(false);
			this->classificationTabPage->ResumeLayout(false);
			this->classificationTabPage->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingCMDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingEvaluationDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testEvaluationDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testCMDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classificationDataGridView))->EndInit();
			this->regressionTabPage->ResumeLayout(false);
			this->regressionTabPage->PerformLayout();
			this->regressionPercentageTableLayoutPanel->ResumeLayout(false);
			this->regressionPercentageTableLayoutPanel->PerformLayout();
			this->regressionTestTableLayoutPanel->ResumeLayout(false);
			this->regressionTestTableLayoutPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trainingRegressionChart))->EndInit();
			this->regressionTrainingTableLayoutPanel->ResumeLayout(false);
			this->regressionTrainingTableLayoutPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testRegressionChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->regressionDataGridView))->EndInit();
			this->clusteringTabPage->ResumeLayout(false);
			this->clusteringTabPage->PerformLayout();
			this->clusteringEvaluationTableLayoutPanel->ResumeLayout(false);
			this->clusteringEvaluationTableLayoutPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clusteringChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clusteringDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion






	private: System::Void calassificationRunButton_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ trainingSetText = classificationTraningSetTextBox->Text;
		System::String^ testSetText = classificationTestSetTextBox->Text;

		int value1 = checkDataPercentage(trainingSetText, testSetText);
		std::string filePath = msclr::interop::marshal_as<std::string>(classificationDataPathTextBox->Text);
		if (value1 == -1) {
			MessageBox::Show("Please enter percentage of training and testing dataset..");
		}
		else {
			// Determine the algorithm based on the selected item
			int algorithmIndex = classificationAlgorithmListBox->SelectedIndex;

			if (algorithmIndex == 0) {
				if (value1 != -1) {
					// KNN Classifier //
					KNNClassifier knnClassifier(5);

					// Evaluation //

					auto resultTuple = knnClassifier.runKNNClassifier(filePath, value1);

					// Unpack the results from the tuple
					double test_accuracy, train_accuracy;
					std::vector<double> trainLabels, trainPredictions, testLabels, testPredictions;

					std::tie(train_accuracy, test_accuracy, trainLabels, trainPredictions, testLabels, testPredictions) = resultTuple;
					trainingAccuracyTextBox->Clear();
					trainingAccuracyTextBox->Text = Convert::ToString(train_accuracy);
					testAccuracyTextBox->Clear();
					testAccuracyTextBox->Text = Convert::ToString(test_accuracy);

					// Visualization //
					//	 Define the number of class label for which you want to calculate the Evaluation Metrics and confusion Matrix
					int numClasses = 3;
					DisplayEvaluationMetricsInDataGridView(trainingEvaluationDataGridView, trainLabels, trainPredictions, numClasses);
					DisplayEvaluationMetricsInDataGridView(testEvaluationDataGridView, testLabels, testPredictions, numClasses);
					DisplayConfusionMatrixInGrid(trainingCMDataGridView, trainLabels, trainPredictions, numClasses);
					DisplayConfusionMatrixInGrid(testCMDataGridView, testLabels, testPredictions, numClasses);

				}

			}
			else if (algorithmIndex == 1) {
				if (value1 != -1) {
					// Decision Tree Classification //

					DecisionTreeClassification dtClassification;

					// Evaluation //

					auto resultTuple = dtClassification.runDecisionTreeClassification(filePath, value1);

					// Unpack the results from the tuple
					double test_accuracy, train_accuracy;
					std::vector<double> trainLabels, trainPredictions, testLabels, testPredictions;

					std::tie(train_accuracy, test_accuracy, trainLabels, trainPredictions, testLabels, testPredictions) = resultTuple;
					trainingAccuracyTextBox->Clear();
					trainingAccuracyTextBox->Text = Convert::ToString(train_accuracy);
					testAccuracyTextBox->Clear();
					testAccuracyTextBox->Text = Convert::ToString(test_accuracy);

					// Visualization //
					//	 Define the number of class label for which you want to calculate the Evaluation Metrics and confusion Matrix
					int numClasses = 3;
					DisplayEvaluationMetricsInDataGridView(trainingEvaluationDataGridView, trainLabels, trainPredictions, numClasses);
					DisplayEvaluationMetricsInDataGridView(testEvaluationDataGridView, testLabels, testPredictions, numClasses);
					DisplayConfusionMatrixInGrid(trainingCMDataGridView, trainLabels, trainPredictions, numClasses);
					DisplayConfusionMatrixInGrid(testCMDataGridView, testLabels, testPredictions, numClasses);


				}

			}
			else if (algorithmIndex == 2) {
				if (value1 != -1) {

					LogisticRegression LogiRegression;

					// Evaluation //

					auto resultTuple = LogiRegression.runLogisticRegression(filePath, value1);

					// Unpack the results from the tuple
					double test_accuracy, train_accuracy;
					std::vector<double> trainLabels, trainPredictions, testLabels, testPredictions;

					std::tie(train_accuracy, test_accuracy, trainLabels, trainPredictions, testLabels, testPredictions) = resultTuple;
					trainingAccuracyTextBox->Clear();
					trainingAccuracyTextBox->Text = Convert::ToString(train_accuracy);
					testAccuracyTextBox->Clear();
					testAccuracyTextBox->Text = Convert::ToString(test_accuracy);

					// Visualization //
					//	 Define the number of class label for which you want to calculate the Evaluation Metrics and confusion Matrix
					int numClasses = 3;
					DisplayEvaluationMetricsInDataGridView(trainingEvaluationDataGridView, trainLabels, trainPredictions, numClasses);
					DisplayEvaluationMetricsInDataGridView(testEvaluationDataGridView, testLabels, testPredictions, numClasses);
					DisplayConfusionMatrixInGrid(trainingCMDataGridView, trainLabels, trainPredictions, numClasses);
					DisplayConfusionMatrixInGrid(testCMDataGridView, testLabels, testPredictions, numClasses);


				}

			}
			else {
				MessageBox::Show("Please select regression algorithm.");
			}
		}
	}


	private: System::Void regressionRuntButton_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ trainingSetText = regressionTraningSetTextBox->Text;
		System::String^ testSetText = regressionTestSetTextBox->Text;

		int value1 = checkDataPercentage(trainingSetText, testSetText);
		std::string filePath = msclr::interop::marshal_as<std::string>(regressionDataPathTextBox->Text);
		if (value1 == -1) {
			MessageBox::Show("Please enter percentage of training and testing dataset..");
		}
		else {
			// Determine the algorithm based on the selected item
			int algorithmIndex = regressionAlgorithmListBox->SelectedIndex;

			if (algorithmIndex == 0) {
				if (value1 != -1) {

					// KNN Regression //
					KNNRegression knnRegression(3);

											// Evaluation //

					auto resultTuple = knnRegression.runKNNRegression(filePath, value1);

					// Unpack the results from the tuple
					double test_mae, test_rmse, test_rsquared, train_mae, train_rmse, train_rsquared;
					std::vector<double> trainLabels, trainPredictions, testLabels, testPredictions;

					std::tie(test_mae, test_rmse, test_rsquared,
						train_mae, train_rmse, train_rsquared,
						trainLabels, trainPredictions, testLabels, testPredictions) = resultTuple;
					maeTestTextBox->Clear();
					maeTestTextBox->Text = Convert::ToString(test_mae);
					rmseTestTextBox->Clear();
					rmseTestTextBox->Text = Convert::ToString(test_rmse);
					rSquaredTestTextBox->Clear();
					rSquaredTestTextBox->Text = Convert::ToString(test_rsquared);
					maeTrainTextBox->Clear();
					maeTrainTextBox->Text = Convert::ToString(train_mae);
					rmseTrainTextBox->Clear();
					rmseTrainTextBox->Text = Convert::ToString(train_rmse);
					rSquaredTrainTextBox->Clear();
					rSquaredTrainTextBox->Text = Convert::ToString(train_rsquared);

											// Visualization //
					VisualizeParityPlot(testLabels, testPredictions, testRegressionChart);
					VisualizeParityPlot(trainLabels, trainPredictions, trainingRegressionChart);

				}

			}
			else if (algorithmIndex == 1) {
				if (value1 != -1) {
					// running the linear regression

					LinearRegression LR;

					// Evaluation //

					auto resultTuple = LR.runLinearRegression(filePath, value1);

					// Unpack the results from the tuple
					double test_mae, test_rmse, test_rsquared, train_mae, train_rmse, train_rsquared;
					std::vector<double> trainLabels, trainPredictions, testLabels, testPredictions;

					std::tie(test_mae, test_rmse, test_rsquared,
						train_mae, train_rmse, train_rsquared,
						trainLabels, trainPredictions, testLabels, testPredictions) = resultTuple;
					maeTestTextBox->Clear();
					maeTestTextBox->Text = Convert::ToString(test_mae);
					rmseTestTextBox->Clear();
					rmseTestTextBox->Text = Convert::ToString(test_rmse);
					rSquaredTestTextBox->Clear();
					rSquaredTestTextBox->Text = Convert::ToString(test_rsquared);
					maeTrainTextBox->Clear();
					maeTrainTextBox->Text = Convert::ToString(train_mae);
					rmseTrainTextBox->Clear();
					rmseTrainTextBox->Text = Convert::ToString(train_rmse);
					rSquaredTrainTextBox->Clear();
					rSquaredTrainTextBox->Text = Convert::ToString(train_rsquared);

					// Visualization //
					VisualizeParityPlot(testLabels, testPredictions, testRegressionChart);
					VisualizeParityPlot(trainLabels, trainPredictions, trainingRegressionChart);

				}
	
			}
			else if (algorithmIndex == 2) {
				if (value1 != -1) {
					// //Decision Tree Regression //
					
					DecisionTreeRegression dtRegression;

					// Evaluation //

					auto resultTuple = dtRegression.runDecisionTreeRegression(filePath, value1);

					// Unpack the results from the tuple
					double test_mae, test_rmse, test_rsquared, train_mae, train_rmse, train_rsquared;
					std::vector<double> trainLabels, trainPredictions, testLabels, testPredictions;

					std::tie(test_mae, test_rmse, test_rsquared,
						train_mae, train_rmse, train_rsquared,
						trainLabels, trainPredictions, testLabels, testPredictions) = resultTuple;
					maeTestTextBox->Clear();
					maeTestTextBox->Text = Convert::ToString(test_mae);
					rmseTestTextBox->Clear();
					rmseTestTextBox->Text = Convert::ToString(test_rmse);
					rSquaredTestTextBox->Clear();
					rSquaredTestTextBox->Text = Convert::ToString(test_rsquared);
					maeTrainTextBox->Clear();
					maeTrainTextBox->Text = Convert::ToString(train_mae);
					rmseTrainTextBox->Clear();
					rmseTrainTextBox->Text = Convert::ToString(train_rmse);
					rSquaredTrainTextBox->Clear();
					rSquaredTrainTextBox->Text = Convert::ToString(train_rsquared);

					// Visualization //
					VisualizeParityPlot(testLabels, testPredictions, testRegressionChart);
					VisualizeParityPlot(trainLabels, trainPredictions, trainingRegressionChart);
					
				}

			}
			else {
				MessageBox::Show("Please select regression algorithm.");
			}
		}
	}



	private: System::Void clusteringRunButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string filePath = msclr::interop::marshal_as<std::string>(clusteringDataPathTextBox->Text);

		if (filePath.empty()) {
			MessageBox::Show("First load data from the path.");
		}
		else {
			// Load and preprocess data
			std::vector<std::vector<double>> X;
			std::vector<double> y;

			// Determine the algorithm based on the selected item
			int algorithmIndex = clusteringAlgorithmListBox->SelectedIndex;

			if (algorithmIndex == 0) {
				// K-Means Clustering//
				int numClusters = 3;
				int maxIterations = 100;
				KMeans kmeans(numClusters, maxIterations);

				// Evaluation //
				auto resultTuple = kmeans.runKMeans(filePath);

				// Unpack the results from the tuple
				double daviesBouldinIndex, silhouetteScore;
				std::vector<int> labels;
				std::vector<std::vector<double>> reduced_data;

				std::tie(daviesBouldinIndex, silhouetteScore, labels, reduced_data) = resultTuple;
				daviesBouldinIndexTextBox->Clear();
				daviesBouldinIndexTextBox->Text = Convert::ToString(daviesBouldinIndex);
				silhouetteScoreTextBox->Clear();
				silhouetteScoreTextBox->Text = Convert::ToString(silhouetteScore);

				// Visualization //

				PlotReducedDimensionalData(clusteringChart, reduced_data, labels,  numClusters);


			}
			else if (algorithmIndex == 1) {
				// FuzzyCMeans Clustering//
				int numClusters = 3; // Set the number of clusters
				int maxIterations = 100; // Set the maximum number of iterations
				double fuzziness = 2.0; // Set the fuzziness parameter
				FuzzyCMeans fcm(numClusters, maxIterations, fuzziness);
			

				// Evaluation //
				auto resultTuple = fcm.runFuzzyCMeans(filePath);

				// Unpack the results from the tuple
				double daviesBouldinIndex, silhouetteScore;
				std::vector<int> labels;
				std::vector<std::vector<double>> reduced_data;

				std::tie(daviesBouldinIndex, silhouetteScore, labels, reduced_data) = resultTuple;
				daviesBouldinIndexTextBox->Clear();
				daviesBouldinIndexTextBox->Text = Convert::ToString(daviesBouldinIndex);
				silhouetteScoreTextBox->Clear();
				silhouetteScoreTextBox->Text = Convert::ToString(silhouetteScore);

				// Visualization //

				PlotReducedDimensionalData(clusteringChart, reduced_data, labels, numClusters);


			}
			else {
				MessageBox::Show("Please select clustering algorithm.");
			}
		}
	}


	private: System::Void regressionBrowseButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		LoadBrowsedData(regressionDataPathTextBox, regressionDataGridView);
	}


	private: System::Void classificationBrowseButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		LoadBrowsedData(classificationDataPathTextBox, classificationDataGridView);
	}


	private: System::Void clusteringBrowseButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		LoadBrowsedData(clusteringDataPathTextBox, clusteringDataGridView);
	}

// Function to populate the regressionDataGridView
	void PopulateDataGridView(System::Windows::Forms::DataGridView^ DataGridView, const std::vector<std::vector<std::string>>& data)
	{
	// Clear existing columns and rows
	DataGridView->Columns->Clear();
	DataGridView->Rows->Clear();

	// Add columns dynamically based on the dataset structure
	if (!data.empty())
	{
		int numColumns = data[0].size();
		for (int i = 0; i < numColumns - 1; ++i) // Exclude the last column
		{
			System::Windows::Forms::DataGridViewTextBoxColumn^ column = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			column->HeaderText = gcnew System::String(data[0][i].c_str()); // Set header from the first row
			column->Name = "column" + i;
			column->ReadOnly = true;

			DataGridView->Columns->Add(column);
		}
	}

	// Add the last column with the name "Label"
	System::Windows::Forms::DataGridViewTextBoxColumn^ lastColumn = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
	lastColumn->HeaderText = "Label";
	lastColumn->Name = "columnLabel";
	lastColumn->ReadOnly = true;
	DataGridView->Columns->Add(lastColumn);

	// Add rows to the DataGridView, starting from the second row
	for (int rowIndex = 1; rowIndex < data.size(); ++rowIndex)
	{
		const auto& row = data[rowIndex];
		int newRowIdx = DataGridView->Rows->Add();

		for (int i = 0; i < row.size(); ++i)
		{
			if (i == row.size() - 1) // Last column
			{
				DataGridView->Rows[newRowIdx]->Cells[i]->Value = gcnew System::String(row[i].c_str());
			}
			else
			{
				DataGridView->Rows[newRowIdx]->Cells[i]->Value = gcnew System::String(row[i].c_str());
			}
		}
	}

}


int checkDataPercentage(System::String^ trainingSetText, System::String^ testSetText) {
	// Copying text from text box to string variable.
	System::String^ input1 = trainingSetText;
	System::String^ input2 = testSetText;

	// Check if the values are empty
	if (String::IsNullOrEmpty(input1) || String::IsNullOrEmpty(input2)) {
		MessageBox::Show("Please enter percentage of training and testing dataset.");
		
	}
	else {
		// Convert the input strings to integers
		int value1 = 0;
		int value2 = 0;
		bool isValue1Valid = Int32::TryParse(input1, value1);
		bool isValue2Valid = Int32::TryParse(input2, value2);

		if (isValue1Valid && isValue2Valid) {
			// Check if the values are not empty and within the specified range
			if (value1 + value2 == 100) {
				if (value1 >= 50 && value1 <= 85) {
					return value1;
				}
				else {
					MessageBox::Show("Training Set should be greater than 50 and less than 85");
				}
			}
			else {
				MessageBox::Show("Balance between training and test set is not equal.");
			}
		}
		else {
			MessageBox::Show("No Numeric.");
		}
	}

	return -1; // Indicate failure or default value
}


void VisualizeParityPlot(std::vector<double>& y_test, std::vector<double>& y_pred, System::Windows::Forms::DataVisualization::Charting::Chart^ regressionChart) {
	// Clear any existing data in the regressionChart
	regressionChart->Series[0]->Points->Clear();

	// Set axis labels and title
	regressionChart->ChartAreas[0]->AxisX->Title = "Benchmark Data";
	regressionChart->ChartAreas[0]->AxisY->Title = "Computational Model";

	regressionChart->Titles->Clear();
	regressionChart->Titles->Add("Parity Plot");

	regressionChart->Width = 400;
	regressionChart->Height = 300;

	// Assuming you have y_test and y_pred vectors
	for (int i = 0; i < y_test.size(); ++i) {
		double benchmark = y_test[i];
		double modelResult = y_pred[i];

		regressionChart->Series[0]->Points->AddXY(benchmark, modelResult);
	}

	// Set the regressionChart type to scatter plot
	regressionChart->Series[0]->ChartType = DataVisualization::Charting::SeriesChartType::Point;

	// Customize marker style and color
	regressionChart->Series[0]->MarkerStyle = DataVisualization::Charting::MarkerStyle::Circle;
	regressionChart->Series[0]->MarkerSize = 8;
	regressionChart->Series[0]->MarkerColor = System::Drawing::Color::Blue;
}


void LoadBrowsedData(System::Windows::Forms::TextBox^ dataPathTextBox, DataGridView^ dataGridView) {
	OpenFileDialog^ dataOpenFileDialog = gcnew OpenFileDialog;
	//System::Windows::Forms::TextBox^ dataPathTextBox = nullptr;
	dataOpenFileDialog->InitialDirectory = "c:\\";
	dataOpenFileDialog->Filter = "csv files (*.csv)|*.csv|All files (*.*)|*.*";
	dataOpenFileDialog->FilterIndex = 2;
	dataOpenFileDialog->RestoreDirectory = true;

	if (dataOpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		dataPathTextBox->Text = dataOpenFileDialog->FileName;
		std::string filePath = msclr::interop::marshal_as<std::string>(dataPathTextBox->Text);

		// Read and parse the dataset file
		std::vector<std::vector<std::string>> data = DataLoader::readDatasetFromFilePath(filePath);

		// Display data in the DataGridView
		PopulateDataGridView(dataGridView, data);
	}
}


void DisplayEvaluationMetricsInDataGridView(DataGridView^ dataGridView, const std::vector<double>& y_test, const std::vector<double>& y_pred, int numClasses) {
	// Clear any existing data in the dataGridView
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	// Add columns to the dataGridView for each class label
	dataGridView->Columns->Add("Class", "Class");
	dataGridView->Columns->Add("Recall", "Recall");
	dataGridView->Columns->Add("Precision", "Precision");
	dataGridView->Columns->Add("F1 Score", "F1 Score");

	// Add rows to the grid for each class label
	for (int i = 0; i < numClasses; i++) {
		// Convert class label to string and add as row header
		System::String^ rowHeader = gcnew System::String(std::to_string(i + 1).c_str());
		dataGridView->Rows->Add(rowHeader);

		// Calculate recall for the current class label
		double recall = Metrics::recall(y_test, y_pred, i + 1);
		// Convert recall to string and set in the dataGridView
		System::String^ recallValue = gcnew System::String(std::to_string(recall).c_str());
		dataGridView->Rows[i]->Cells[1]->Value = recallValue;

		// Calculate precision for the current class label
		double precision = Metrics::precision(y_test, y_pred, i + 1);
		// Convert precision to string and set in the dataGridView
		System::String^ precisionValue = gcnew System::String(std::to_string(precision).c_str());
		dataGridView->Rows[i]->Cells[2]->Value = precisionValue;

		// Calculate F1 score for the current class label
		double f1Score = Metrics::f1Score(y_test, y_pred, i + 1);
		// Convert F1 score to string and set in the dataGridView
		System::String^ f1ScoreValue = gcnew System::String(std::to_string(f1Score).c_str());
		dataGridView->Rows[i]->Cells[3]->Value = f1ScoreValue;
	}
}


void DisplayConfusionMatrixInGrid(DataGridView^ dataGridView, const std::vector<double>& y_test, 
	const std::vector<double>& y_pred, int numClasses) {
	// Calculate confusionMatrix for the specified number of class labels
	std::vector<std::vector<int>> confusionMatrix = Metrics::confusionMatrix(y_test, y_pred, numClasses);

	// Clear any existing data in the dataGridView
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	// Add columns to the dataGridView for each class label
	for (int i = 0; i < numClasses; i++) {
		// Convert class label to string and add as column header
		System::String^ columnHeader = gcnew System::String(("Class " + std::to_string(i + 1)).c_str());
		dataGridView->Columns->Add(columnHeader, columnHeader);
	}

	// Add rows to the dataGridView for each class label
	for (int i = 0; i < numClasses; i++) {
		// Convert class label to string and add as row header
		System::String^ rowHeader = gcnew System::String(("Class " + std::to_string(i + 1)).c_str());
		dataGridView->Rows->Add(rowHeader, rowHeader);

		// Populate the dataGridView with values from the confusion matrix
		for (int j = 0; j < numClasses; j++) {
			// Convert cell value to string and set in the dataGridView
			System::String^ cellValue = gcnew System::String(std::to_string(confusionMatrix[i][j]).c_str());
			dataGridView->Rows[i]->Cells[j]->Value = cellValue;
		}
	}
}


void PlotReducedDimensionalData(System::Windows::Forms::DataVisualization::Charting::Chart^ chart, const std::vector<std::vector<double>>& reduced_data,
	const std::vector<int>& labels, int numClusters) {
	std::vector<double> Principal_Component_1(reduced_data.size());
	std::vector<double> Principal_Component_2(reduced_data.size());
	for (int i = 0; i < reduced_data.size(); ++i) {
		Principal_Component_1[i] = reduced_data[i][0];
		Principal_Component_2[i] = reduced_data[i][1];
	}

	chart->Series[0]->Points->Clear();
	chart->ChartAreas[0]->AxisX->Title = "Principal Component 1";
	chart->ChartAreas[0]->AxisY->Title = "Principal Component 2";
	chart->Titles->Clear();
	chart->Titles->Add("K-means Clustering Result");
	chart->Width = 600;
	chart->Height = 400;

	for (int i = 1; i <= numClusters; ++i) {
		for (int j = 0; j < labels.size(); ++j) {
			if (labels[j] == i) {
				chart->Series[0]->Points->AddXY(Principal_Component_1[j], Principal_Component_2[j]);

				if (i == 1)
					chart->Series[0]->Points[chart->Series[0]->Points->Count - 1]->Color = System::Drawing::Color::Red;
				else if (i == 2)
					chart->Series[0]->Points[chart->Series[0]->Points->Count - 1]->Color = System::Drawing::Color::Green;
				else if (i == 3)
					chart->Series[0]->Points[chart->Series[0]->Points->Count - 1]->Color = System::Drawing::Color::Blue;
			}
		}
	}
}



private: System::Void classificationAlgorithmListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
