import os

data=[
    [['int'], ['disp_min'], ['DispMin']],
    [['int'], ['disp_max'], ['DispMax']],
    [['double'], ['support_threshold'], ['SupportThreshold']],
    [['int'], ['support_texture'], ['SupportTexture']],
    [['int'], ['candidate_stepsize'], ['CSandidateStepsize']],
    [['int'], ['incon_window_size'], ['InconWindowSize']],
    [['int'], ['incon_threshold'], ['InconThreshold']],
    [['int'], ['incon_min_support'], ['InconMinSupport']],
    [['bool'], ['add_corners'], ['AddCorners']],
    [['int'], ['grid_size'], ['GridSize']],
    [['double'], ['beta'], ['Beta']],
    [['double'], ['gamma'], ['Gamma']],
    [['double'], ['sigma'], ['Sigma']],
    [['double'], ['sradius'], ['Sradius']],
    [['int'], ['match_texture'], ['MatchTexture']],
    [['int'], ['lr_threshold'], ['LrThreshold']],
    [['double'], ['speckle_sim_threshold'], ['SpeckleSimThreshold']],
    [['int'], ['speckle_size'], ['SpeckleSize']],
    [['int'], ['ipol_gap_width'], ['IpolGapWidth']],
    [['bool'], ['filter_median'], ['FilterMedian']],
    [['bool'], ['filter_adaptive_mean'], ['FilterAdaptiveMean']],
    [['bool'], ['postprocess_only_left'], ['PostprocessOnlyLeft']],
    [['bool'], ['subsampling'], ['SubSampling']]
]


file_object = open('Code.txt', 'w')
# file_object.writelines(list_of_text_strings)
# file_object.close()

# 1.StereoMatchParamEntity.h中的变量

'''
2.StereoMatchParamEntity.h中的signals
    void paramChanged_变量名();
'''
file_object.write("+++++++++++++++2++++++++++++++++\n")
signals_text=""
for item in data:
    temp="void paramChanged_"+item[1][0]+"();\n"
    signals_text+=temp
    print(temp)
file_object.write(signals_text)
'''
3. StereoMatchParamEntity.h中的get和set
    void set变量名首字母大写(变量类型 value);
    变量类型 get变量名首字母大写();
'''
file_object.write("+++++++++++++++3++++++++++++++++\n")
getAndset=""
for item in data:
    temp = "void set"+item[2][0]+"("+item[0][0]+" value);\n"
    temp+= item[0][0]+" get"+item[2][0]+"();\n"
    getAndset+=temp
    print(temp)
file_object.writelines(getAndset)
'''
4. StereoMatchParamEntity.cpp中的get和Set的实现
    void StereoMatchParamEntity::set变量名首字母大写(变量类型 value){
        变量名=value;
        emit paramChanged_变量名();
    }
    变量类型 StereoMatchParamEntity::get变量名首字母大写(){
        return 变量;
    }
'''
file_object.write("+++++++++++++++4++++++++++++++++\n")
real_getandset=""
for item in data:
    temp ="void StereoMatchParamEntity::set"+item[2][0]+"("+item[0][0]+" value){\n    "+\
          item[1][0]+"=value;\n    emit paramChanged_"+item[1][0]+"();\n}\n"
    temp+=item[0][0]+" StereoMatchParamEntity::get"+item[2][0]+"(){\n"+\
    "    return "+item[1][0]+";\n}\n"
    real_getandset+=temp
    print(temp)
file_object.writelines(real_getandset)
'''
# 5.MatcherView.h中的函数定义
    void valueChanged_变量名首字母大写(变量类型 value);
	void onParamChanged_变量名首字母大写();
'''
file_object.write("+++++++++++++++5++++++++++++++++\n")
slots=""
for item in data:
    temp ="void valueChanged_"+item[2][0]+"("+item[0][0]+" value);\n"
    temp+="void onParamChanged_"+item[2][0]+"();\n"
    slots+=temp
    print(temp)
file_object.writelines(slots)
'''
# 6.MatcherView.cpp中的函数实现
    void MatcherView::valueChanged_变量名首字母大写(变量类型 value){
	    if (m_entity->get变量名首字母大写() != value)
	    {
		    m_entity->set变量名首字母大写(value);
	    }
    }
    void MatcherView::onParamChanged_变量名首字母大写(){
        ui.变量控件名->SetValue(m_entity->get变量名首字母大写());//根据变量类型的不同,此处有所不同
    }
'''
file_object.write("+++++++++++++++6++++++++++++++++\n")
real_slots=""
for item in data:
    temp ="void MatcherView::valueChanged_"+item[2][0]+"("+item[0][0]+" value){\n"+\
        "    if (m_entity->get"+item[2][0]+"() != value)\n    {\n"+\
        "        m_entity->set"+item[2][0]+"(value);\n    }\n}\n"
    temp+="void MatcherView::onParamChanged_"+item[2][0]+"(){\n    ui."
    if item[0][0]=="int":
        temp+="spinBox_"
    if item[0][0]=="double":
        temp+="doubleSpinBox_"
    if item[0][0]=="bool":
        temp+="checkBox_"
    temp+=item[1][0]+"->"
    if item[0][0]=="int":
        temp+="setValue"
    if item[0][0]=="double":
        temp+="setValue"
    if item[0][0]=="bool":
        temp+="setChecked"
    temp+="(m_entity->get"+item[2][0]+"());\n}\n"
    real_slots+=temp
    print(temp)
file_object.writelines(real_slots)
'''
# 7.Matcher.cpp构造函数中的信号槽链接
 connect(m_entity, SIGNAL(paramChanged_变量名()), this, SLOT(onParamChanged_变量名首字母大写()));
'''
file_object.write("+++++++++++++++7++++++++++++++++\n")
connects=""
for item in data:
    temp ="connect(m_entity, SIGNAL(paramChanged_"+item[1][0]+"()), this, SLOT(onParamChanged_"+item[2][0]+"()));\n"
    connects+=temp
    print(temp)
file_object.writelines(connects)
file_object.close()