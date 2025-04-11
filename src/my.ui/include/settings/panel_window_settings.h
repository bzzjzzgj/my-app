#pragma once


namespace MyUI::Settings
{
	/**
	* 发送到面板窗口构造函数以定义其设置的数据结构。
	*/
	struct PanelWindowSettings
	{
		bool closable					= false;
		bool resizable					= true;
		bool movable					= true;
		bool dockable					= false;
		bool scrollable					= true;
		bool hideBackground				= false;
		bool forceHorizontalScrollbar	= false;
		bool forceVerticalScrollbar		= false;
		bool allowHorizontalScrollbar	= false;
		bool bringToFrontOnFocus		= true;
		bool collapsable				= false;
		bool allowInputs				= true;
		bool titleBar					= true;
		bool autoSize					= false;
	};
}