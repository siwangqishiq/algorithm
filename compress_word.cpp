/***
 * 
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

  例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

 

示例：

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 7
每个单词都是小写字母 。
 * 
 * */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

//检测checkstr 是否是 srcStr的后缀   
bool checkWordIsSuffix(std::string &srcStr , std::string &checkStr) {
    if(srcStr == checkStr)
        return true;

    if(srcStr.length() < checkStr.length())
        return false;

    int offset = srcStr.length() - checkStr.length();
    for(int i = checkStr.length() - 1 ; i >= 0 ; i--){
        if(checkStr[i] != srcStr[offset + i]){
            return false;
        }
    }

    return true;
}

struct WordInfo{
    string content;
    vector<shared_ptr<pair<int, int>>> relatedIndexes; //与此单词关联的
    int preLength;
};

string buildWordString(vector<WordInfo> &wordInfoList , vector<shared_ptr<pair<int, int>>> &indexList){
    string result;
    vector<int> indexes;

    for(WordInfo &info : wordInfoList){
        info.preLength = result.length();
        result += (info.content + string("#"));
    }//end for each
    cout << result << endl;

    for(shared_ptr<pair<int, int>> &p : indexList){
        WordInfo &wordInfo = wordInfoList[p->first];
        int offset = wordInfo.preLength + p->second;
        
        indexes.push_back(offset);
    }//end for each

    // cout << "[ ";
    // for(int &i : indexes){
    //     cout << i << " ";
    // }//end for each
    // cout << "]" << endl;

    return result;
}

int minimumLengthEncoding(vector<string>& words) {
    vector<WordInfo> wordInfoList;
    vector<shared_ptr<pair<int, int>>> indexList;

    //todo encode
    for(int i = 0 ; i < words.size(); i++){
        string &word = words[i];
        //cout << word << endl;
        
        bool hasFindWordInfo = false;
        for(int j = 0 ; j < wordInfoList.size() ; j++){
            WordInfo &wordInfo = wordInfoList[j];
            string str = wordInfo.content;
            //cout << wordInfo.content << endl;
            
            if(str.length() >= word.length()){ // info content > word
                if(checkWordIsSuffix(str , word)){// 可做压缩存贮
                    hasFindWordInfo = true;

                    const int wordOffset = str.find(word);
                    shared_ptr<pair<int, int>> index = make_shared<pair<int, int>>(make_pair(j , wordOffset));
                    indexList.push_back(index);

                    wordInfo.relatedIndexes.push_back(index);
                    break;
                }
            }else{
                if(checkWordIsSuffix(word , str)){// 可做压缩存贮
                    hasFindWordInfo = true;

                    int delta = word.length() - str.length();
                    wordInfo.content = word;
                    //调整原有数据  换成更大的string
                    for(shared_ptr<pair<int, int>> &p : wordInfo.relatedIndexes){
                        p->second += delta;
                    }//end for each

                    //cout << "word = " << word << "  str = " << str <<endl;
                    shared_ptr<pair<int, int>> index = make_shared<pair<int, int>>(make_pair(j , 0));
                    indexList.push_back(index);
                    wordInfo.relatedIndexes.push_back(index);

                    break;
                }
            }
        }//end for j

        if(!hasFindWordInfo){//add new wordInfo to list
            shared_ptr<pair<int, int>> index = make_shared<pair<int, int>>(make_pair(wordInfoList.size() , 0 ));
            indexList.push_back(index);

            WordInfo wordInfo;
            wordInfo.content = word;
            wordInfo.relatedIndexes.push_back(index);

            wordInfoList.push_back(wordInfo);
        }
    }//end for i
    //
    string encodeString = buildWordString(wordInfoList , indexList);
    return encodeString.length();
}

int main(int argc , char *argv[]) {
    vector<std::string> words = {"rzgecnb","ksnurny","wxbke","rmbjxa","heired","cubdk","mavzbs","rcbnfqs","dexwwl","gfxrtwe","hoxdjzo","gwbwen","tkivioj","oghxaro","iqgwx","rikafxa","xbnaq","iurvl","cfgees","qgvpv","bbonp","uswkb","hqdqr","fatdgjm","wzmjhro","xpxqvnl","xxyzmtw","ljiztv","ydkwkwq","iormpma","wmbjj","ftnqba","ueemnt","tazmxx","ecueb","lwlsem","bvkutqn","oyvkh","plvrr","xznsks","orrxdrv","cpzplb","hdeqepx","qktom","peujscv","nctedf","wcrxj","tenjmd","ofkkgsn","onwifye","crypx","cuwmlr","gyoxru","snrdlco","manrvnf","oocgqi","tqogpta","aoaox","kqugb","ygkqxc","omyenl","lxmit","dqxlw","qtqzw","bmdkbkb","ojtkn","pdkeelu","btfzad","bzyrx","htgxqyo","zccauqu","vqwhocj","oralq","haoqxf","mookqql","tmbjoyv","wdahg","bwnmrs","aheaes","yqigoq","xmkrwsi","spqizag","bloxeit","kwxpxj","ckvdbz","pkhqd","vllyaqd","zeqawga","ictog","qawysf","pxsxp","tedys","kjedxdz","vzgeman","aftuvt","fkmpeg","vzlth","xervnk","kuntg","bqjbvj","yayjn","dpvdecg","xpmjh","yiengmx","jhebr","okgfug","rsjud","uezljdn","tunaofq","uuxsssi","bumql","wqjrohr","zpads","umkapdl","sjuclh","wkruy","fkbmd","bwndf","kxnlpbi","noyla","oywof","rutqhz","eqrxksj","rvstrc","cviqubz","upxdmw","zfurc","edvdu","cyjetp","skfxut","obotzcf","izizoe","dbwgi","kepoe","nconc","sigsi","nfiyh","dnsux","btcphf","pnzwq","kcetq","cuvub","ngnjaoi","tbqeadl","idkfu","vkxup","zjwzw","ihqhl","kbahdgp","didvrl","erpbzxw","ktovqii","nmhvtp","oavyl","saodf","rdgvrhy","igjxwod","tkzblfn","oyvznf","cwdju","kfugqf","uuksisi","yvytqic","xcrwdlo","ittdzwl","hvgzabt","cfrirkj","ucqgwv","yeiuyd","ipvkbtq","itvdlm","dmvxu","wbmmxlz","vfhev","ycekw","eknjz","jdvmwr","zdzpodz","bhhhk","wsejvr","oqvljos","znrzk","kkvob","vgtzgsf","jhrno","rsvmgom","xczvot","aatvdsh","cfmaus","quygvn","zflogpr","zvwxge","zdutmti","tpjlrs","bvetgt","rlarhzm","ddkszg","sumwvgf","adqclo","hqxcvt","bqdftd","pcswvir","beudr","sunle","lverbso","ccxoocp","zknty","jxslpkv","ekbyip","bvutjx","dttchmx","kzmwseb","npkpysg","ydthy","sthol","gbknrps","yxrootu","ykolunw","sojcrgm","swwoht","gtkyot","vnsect","hociud","bjefjy","sxjnc","mzctff","omkra","hjcaoyf","qercwcf","wyhpaap","eyeagj","hgnqxce","jvttwo","jkegf","mafyijx","zixiahs","fgqkr","etibkcy","mlgaabi","bjimff","bqtfvgv","kpnsawg","vmkgrh","djqtbjz","gdfjvi","mytmjub","nmjhyit","xucrph","nwhnlfb","esjeb","urlcs","obcrly","xhzpobq","eqjyjtj","olnejtc","ziozhi","rdmyljo","dxvcxo","hsuetvr","phwhwng","nfkcp","bapfj","nuwddzw","vottsqn","jnlckw","omqjqmz","lrapgpu","svgoghf","mhmkf","tjkiuo","wmizv","exogiss","ixzgrzs","swrmuej","lmddcb","uszdqa","fchkl","hkfgwoj","sewnrue","vcijwy","wowllb","whkgd","ndtwkmq","qhqjgbk","nyiuech","jjcvg","rigcdgz","xtnlhrm","kmevrup","fgltdlz","lzhym","luhyx","fhctjpx","jnipsod","szvfqr","ckkxno","ounnz","ngtjg","whdec","lwssoox","fjrimc","hrcgnf","hlyps","frlzjd","dufyjqa","ddhkmy","ovgse","oxotneg","zwfrfp","ftbyud","rfmnk","lrveen","llikmi","xsjeqk","vnvvchw","obnnod","jyhcbd","ebitk","peunztp","nnyyghs","dvjlsrx","kswveud","enqgxd","ffoaxe","ozoycvd","uoscvwm","lgckjji","xdgvpm","pfuaovi","flxsb","sbkeelx","ezptldl","erwdzpm","vnitst","asokpg","fxbyf","orqwif","ztyqzdk","vtxsauv","ukpleg","roooh","avgli","viwuq","hzjrrmf","tifio","evrisc","czgouwp","ujcjwso","qrvhj","aaqdlmb","vxfula","bnhfc","eqxgw","iiiyo","istcie","voarm","srukm","gzqmdj","ehowtm","nzvij","uiavo","oixqn","uhrkwfz","rmnxtqh","bhtgpp","trthxob","bgnsmy","dcladb","aikgh","tqygzfz","zlrhyqp","jlusbo","jhlsl","gerzkq","cusihd","oaunje","evtvt","owtzbe","bihuj","dquvd","tyekhr","zosjiye","dwtbnxw","kbxdgud","sietpg","tljojx","rhbrcjj","qzwjr","fddiz","ukzwcsr","mttoi","kpnzmaz","bofvmh","ryvxjrf","muuiisk","btuuzmf","vtlxp","pxcma","tnfxgs","jbpnbs","vimckhp","mzneda","wtaee","guwkxw","nazdov","uinmba","xxkyq","dsacuax","tdyguzk","towfm","uycyonz","mfesqlt","csquid","phdhy","uexqg","tlkmq","hxuoqaf","umwxpo","gkqjvf","ibvpu","okfuerx","wytfwt","mngzb","mafqse","htdbrpm","xgbenk","pzojonu","dnwgfe","ffhhikn","iqdiq","yjlqyrx","jtpibev","ychdsb","lrvxa","ddlcz","bjexd","mofjucc","sebqrx","kiwqsx","zpowano","pivmco","vhklg","zarepp","njpge","cvsgyu","lroyzqx","ucpya","dofis","hibdrsg","odlxhr","dvpqb","ibqqqta","gwzdbr","xrlko","physh","ixxzm","nemewa","kfioyr","atwfer","jropga","okmyr","zparndi","czjezxf","frqdvk","yoommid","exbpgro","ztqyveo","hdkpm","mioxflf","nsqyv","vdwujla","gfptwnv","yzhal","yyygtt","jtgyzj","otpohei","yexafp","rxebva","hzppfft","ezqrpc","rfjbfmv","qewiz","apihe","mueltdh","pqsvf","mmqvmha","epwxmr","vjxky","sryurqu","eiedd","vyrdgv","ujbffo","dkjfl","qusoszg","llsugo","nssgis","bzoilj","ksmkylr","wfuvkct","dtatfwi","yeqcp","ampqfi","xzjptgk","laiapn","jyhnw","rdaxh","zurrxkg","dzeekji","wrlgi","owuext","iwrqax","euqvag","traybv","rxeagld","fjnrm","xmuelhd","wyaafzh","nqoout","kdqetbk","czlss","xvlbgcm","vlmjc","azrlo","fridh","szzgznv","llpqme","dxzhyub","exork","smgtzsb","osrvrw","disbpa","tfdgy","pifyrly","mggwzd","uibgie","yolsugm","fhwydj","tftsx","bferm","nxndq","hxniw","gpmexd","fezzt","jqwqsj","xobdzr","wmefo","emlwz","dckrccs","zffzn","awobvm","zbjnm","xskyv","xnjtn","ylvhycd","cawozb","nmwasn","xtwlx","nzyptwx","hmfcpap","wdlgcmj","tisrchy","wfftqyj","ictba","uzlbqm","feryc","cnvjp","ulzqgs","jysay","rgrsh","wnqpkxm","wvcrx","niyftf","flqrz","jhffpl","bzknv","wvbyhz","ytnins","cibgcl","zjiekxa","fjohdc","bhltga","idymcrg","onmuell","licvqbz","eatjwwx","yvvhr","xhfzl","eblrvy","wzyxxvo","eiyidj","zqhsip","wjlaa","losjggh","chxmprz","awawdh","fcgzdn","dueik","dcsvfln","ygemsvv","nmlthnl","iwkfvmb","efzoya","lxeyar","wdakrbo","psijs","dhzhx","qnqhrfy","kowdti","gknpzhj","vsmklr","meqgov","titwocu","ibtqqyz","dugcalq","wtgad","zwytd","gsdnrpt","elysdg","acsegiu","yrzhkwb","xbzvzp","gnlcerh","rdyxaah","wjaiky","vmofg","wvigdn","pqqqzjo","jvads","mxwrjk","denlldr","cvlol","pfucahx","cmunhj","ujutb","zoxmvdu","msogvbp","qypsrq","asrmvj","ihosare","sezgyl","dllal","hbcql","jkwoy","bzoqbl","vtfrxct","hlwabh","maxzn","tmgmwt","hyyqd","bhryg","eaxlcsa","ftmkv","eyyac","dpnotdh","wbpgui","iyllxut","pualv","aqlil","wpwjiit","aymkobe","yiemc","pzocy","rqzpjy","builf","pzdqopi","qaqbrzf","madcrl","chcglb","fnhux","sskapmg","eorhtp","ltqchl","kgqaz","tmtudsz","boaogzq","vcgujf","fdgrv","zkmly","iligr","umnzspn","ezhjlh","tzxetwq","usjtfpc","xoolvn","cmuia","wfbkex","nmwpz","hvnvqsh","fbqrq","xkjaei","ppcioeo","qnhfxq","hlkrl","mrzhfu","hgfueei","xpzluwg","vxndgq","gkbsfx","wyymf","maepjhs","fvmja","ahdpvu","ttkqsxp","eskufcl","pewzsz","cdhyvw","ikkcwfb","snlwx","virez","gfqeei","nhavdec","vbawj","hwdzj","kzwyuk","bzwooss","nzloysi","mtjmyd","kplrkh","btzmmt","sjuhfou","mbkkzjy","plbzugw","mkzkttw","ygtmayh","uivculq","ktyfbd","lbllu","qfkcam","gvlmnsb","etvyww","hmgvpc","xbhiokf","btbwsd","ksgrpk","yiyvwx","uchjcuu","jtwfro","rdqke","ttymxuo","dnmuam","lnhmwqf","hzpdxt","mgcjbgw","ppkbinu","yunjfd","gdaaory","ytlrds","rlvew","gfgied","atkojr","jtvaur","zmygqj","ovroqjq","xpunzuf","kuguuvf","gxlpup","eeozyp","tknpked","trewyyu","xjycj","tspxss","lbuex","notjp","erlnako","fhfvviq","zgssdfl","qhakx","yfzhqps","itkpxkp","rdghnc","rqaja","wnmnpyy","sdagjoj","wxoron","qavslt","jxnbiz","uqodtv","dxzbb","gowwjap","tocoxnc","ckszv","qznio","wsupjv","ojhrxwm","fqmeyy","ofhlt","kvmtz","zzfjaao","dedsiiw","uehzk","xaynjb","xlcqrfe","wyzagh","xbkndev","ofwtibn","slqiamg","pfnjorh","ouxqq","ivjcnuk","mcyoo","clvtae","xmdjn","lalfzlb","rvnar","eunxne","zzkdhai","rxbxk","mcqko","kfcqakv","ravqkt","vhxjips","vlfrka","gstsm","kmezw","pswfvx","dgyuyby","dsljjgk","lltkfea","aobuc","siotm","poszy","gucib","zpwio","mjfmg","lyfwcl","ricbbb","fevcpr","stimyn","jtwaq","fzvec","zpepumr","fbtssq","rmflzj","zjywx","aafeho","bqthot","ymppi","tmrwcq","ddekuu","xkwit","nrgmsb","vtmvkz","vxlua","wozyx","redksd","fxamcsf","cevwc","lrrlet","snjpznj","atcyf","qhlcb","udiuedy","khkbfde","oakqvx","hnsqyud","kxqtz","scknnh","irdyu","dfcwh","digzf","cpfiqbw","iktazoo","djpiq","akzkj","aavcx","yjgbb","axyqixu","xssgsar","mzcawr","qypbptg","ydczslq","jeygocf","unbbse","xgopg","ymqrv","dcxqp","khnvk","iubqfrw","zzyezoe","sjvbmv","nrvdsbh","mmeeza","auuka","jbjiomi","pzqdn","zwshygh","nuniw","pyrvc","khcpi","dvmksjm","krugyk","amyls","htlpsed","qfjkrh","hakcx","cyyskyv","ewqiyfa","cxyzlr","dbjxmi","gwiepf","xkzxxmj","hfmywss","hcpapb","zxpwv","jidcp","cvfqx","hgonqtu","ggbeneq","vrxuwq","fetwnme","rfbdmpi","efyll","aqoxk","ecurvsc","njywhcb","xxbycp","wqexmq","ssjsp","ixcnof","lggcog","lbwyq","hkblnv","jbvpem","upnkplj","yccnxm","cumjcre","lijswsa","zrvix","vfzdi","dslhm","lljnrqq","tkagbk","lykzpq","snzbf","kszqbqj","fsvyeh","miaey","zhqqf","bzdso","jgpvwl","cgbkjdj","caozhg","xqkdm","sspbn","dgcbxt","zopetgi","egpqj","pkszszn","gtyurle","lvawy","rxuwc","jkvopr","ekwljv","bwppek","cevzcue","ynutrz","mpscr","wnvdw","kkjdsv","jeewix","qmozkfg","pjvkfr","aausak","urtulpt","wjaueqn","pgcnw","pmlskv","tsxizxi","jwssnfe","hvdqhc","jqkva","oaagcq","oqqfapk","rbgnfyy","tbyfjh","nhyqf","dflez","qhnwwbi","cvyxj","yvcpyn","rrlfy","gnoyzo","alcujxd","kojwphy","rzlsqz","rrpuo","pdhklbf","fjmhjfi","vwdmd","ncdlyif","ikbjdo","uqdvhtr","evivimc","aypsuz","ybxwx","jmkwfe","tkguccv","pbydgk","xbbjfi","ayqqdfo","agcvbt","yvbdmw","yesttvk","alpatb","ssjyvss","ivklxl","lqeta","chdxdj","fscqzs","vzhwv","maaxza","pqmgi","jcdujn","yyvmdps","tngqzss","fyrfada","yrtpz","muqvvo","qjcosv","xdjhhrv","fojuh","xtmos","lpefgn","hmybxfv","lrkwt","otwhnkj","qpjlg","oatsrl","vaeuy","feduwld","dkowq","lfwpw","cvhizv","alpzmmi","ezmbd","jfhll","fzbrbwy","inlih","gtsmeq","qytuii","yotrqe","zuexo","bbchp","klfzjqn","hzqex","seecbgr","nrbpgdh","rcqqjr","mcdlram","bykhlw","qbccpfd","kfkzp","wkcfsu","efxdh","smlcofd","rrrvsmo","vhxul","gnsds","ayfgzwx","kcxtpo","gpnew","cacpwbl","itwfpvu","pvbsle","qfotexu","vsfhl","krtfbk","udetg","bsktxzl","ttxdpb","dzlnybd","zfzxkrr","ehmzo","yvsky","txtpvj","plonczb","tashdco","jidldyk","fltoy","qwpdg","ysqgh","ftlroqd","kbmjs","fpfkmu","jozfmol","jjsnir","odecqoo","vngnlv","wrpgve","fuvpovj","pjibzot","tmlfuhf","nlqllv","dkazlb","cqlmfg","jzwjsak","tmjlopy","dughuh","tqylj","livjl",
    "dqsvbvl","ewquof","bzemauq","cqxejq","iddwq","ytjkog","dagron","hvufprh","ltzwqbz","pubocyt","nyhfno","pfilwqt","zrppxq","grynnpa","htdhv","rfcgt","soyuwa","uegnm","ocviht","zrvnes","itxgs","yhudf","wzwktk","dicpv","ubczdx","myodjky","ugkkukj","scyyx","uolpbip","hdgptxy","pclfm","nsxmufj","elvtjxf","mkpym","qwtmrev","emprpe","klerq","wbzngx","jrlxgt","ynlbahg","hrtkg","gmunetj","lqstit","dmfeq","jrqaqg","jmevt","qyslrkq","waneb","rqkokm","bswle","avhtso","wlkbae","hxtkdjn","axypf","eaqfkb","bdugg","kqkszy","pciffvl","ovkibef","tqxoy","zgqrtz","yoxsyij","nnquix","xpikpfo","ruhwqc","axrxe","ugtqwvg","hnnen","xmcdf","xbdwlp","zpvpf","qirncnt","rrepzli","qfiseqe","crxisbu","mywgaxs","lzgsiv","oziuvqz","wklrzb","ysozhl","kalxf","wgrohuz","fxqbex","fywqe","txgji","itsel","guzqme","cukvprm","cjqwalo","mepjvk","rzfbis","pvapge","jweiur","wjpnvi","tcaof","hzjkqgx","xravnjj","mkiqire","becrad","dqsfku","oydvv","dyomfi","sqblvm","jmnpcc","annwlv","lzybii","hzdzcb","ubhbk","qcsbi","exvab","slhid","aoghv","ztjuoyi","uxxxlwj","cygshnu","idkna","tguiyhq","tvqlhc","aendq","iyixdo","iuafurc","tujkuke","tfyfiy","nnzhutv","lhjxhpp","cxwpoqv","shikj","fwddklg","owgvnlf","cavtqxf","toolxr","mdpwm","gkyxaiy","yxujmsa","bgalso","pqkry","sldyl","shcyoxk","aonid","xuothx","zaova","stdgv","vpeqzy","xullp","usczzid","tuxoxw","mvvgw","dlljhb","orxyipy","cmpeoov","snmlf","xdrdqh","echlogd","tgvhp","uhyiyqi","xfjlgs","pklxq","ggpulz","aywwh","xplxjz","sjtnaht","rggpliu","twpqkc","jmmidw","isaghil","gdrwjqx","xwuvb","tosyl","kucwbg","uhcga","ylfqytp","uxpirgi","vdfys","xvqkk","ymyvrc","sgvshb","mczhujw","hcggzxx","ldtzqip","hukkceh","tmqqgvz","nytzz","csipaos","bxvgyu","mdvefl","nrlkdcq","jndwwnu","yyuekv","euwymw","uysvz","sadyz","fkrlqt","blfjdm","mfahama","ibzwzc","rwkasv","gxzkro","uiylqhw","nbbiby","ahklcbd","dayzq","kculed","bcjri","estbaze","amnlwh","frzpigs","hzcybee","jzbrxew","cofjyxv","oigcsah","gmeir","yjssagw","gfhvin","oxmuqv","ktyxmu","vhuqe","tytezmh","dzsuo","makhzsa","ifhbn","osfkylr","jtkyon","zobqbar","gqciv","bussbo","mrtqhh","wjxpxnh","vmwzgia","ifnpqs","jkulije","xiqhou","yqjvw","wrsimd","sssquaq","sdddbr","afugj","uzacwa","bexrh","ydmkxxe","pragqak","lzicnq","sontd","fylygf","alnnxun","jpceb","vbonhql","ugkzlh","gcfwm","fxgpadf","brtsdbi","zyngcep","fzltwoq","ldsxj","coajq","qdcvl","lzoyz","xfpgc","kwojy","flfkfg","gedyl","njbyj","afzxm","wgtyblr","lebswo","yzdqpb","yedjll","qziaxc","nfhbjxj","yhhoj","niqhsm","sqeuj","phiwpb","lrlysqm","nobjh","ftmzrai","jfyah","zeuis","pfjutp","hxgtap","uxpjvlk","vcrhyy","odwzqqs","qkkxau","qxksiw","kkcnfm","gsovh","llrgesd","wbkchy","yjzrn","lobcdhv","zqelvlw","ooeyrzg","gjmuabm","mlplco","mqirn","pdhvdbf","qaklds","vtfje","kvjcef","zjvde","kkbtov","wsndjh","frzvdm","nljtmuz","azysmdi","bdnxo","gavwfz","vabqckh","dmymkw","xdzlu","ioufee","csqgzx","kapkakd","bfiwwv","eupka","tlecc","miqoae","boyxt","ynwgms","qyttqs","fonjkm","hsyefaf","uqioyx","moyaxgw","doisv","fwcpkn","xjaol","mwfrowq","wtffgxg","yfehpyw","nlewf","gvxcbm","ysxqo","zhbhm","uxdbowt","zlrby","mxarq","ohykv","vprvaav","gmmkisa","sjzcxny","uitrf","dfbdd","fvuuhk","srilyg","zwvtzg","kscbjwc","dmzuwua","cdjubjk","gzonf","shdur","atbyf","lchifv","tdryh","vzvwvdy","gvtgx","aytazmv","gyczzam","bdbjnuy","eockswe","oazor","azbacy","spxuez","ulvwgru","jcetk","sjqal","tfeaojn","eskxh","tvussew","cfghpqv","zszicrc","hhtaihr","lsmmhe","gethrg","ufxdstj","yfzkdi","vhpbxxl","ppqcfik","yzoabpj","cqydvc","vgijv","gwadznl","zafzfim","blovdji","lgifkf","uyhmor","todhhy","szprsva","ooifvl","ghwqkdj","xruwnu","hwdygu","tpwov","rzktyrd","ivsordk","ahvioub","egnwl","xqxpfk","hepuyf","ujbmtk","enssyo","crjaqry","qdmdnv","zrjriex","eunfpdz","tskoqa","njnfax","wlunp","wxncc","nxqvhzw","iqwejd","aerzbjp","kmmtnp","rtvpl","npubz","mtpdu","ohuxn","bttpggk","cqsgrkh","ncjbhd","cmdlw","fldutdq","olqpln","vclrrqy","ghgansq","rrhrtpg","xzgfzj","birlq","tevnk","dvqyqe","dxdvjs","jexfwdp","wymeef","fiftvhx","rupgfy","uspsqnp","rkcxjx","loflzqf","xifelfi","sidhma","cwttch","dlppnp","ctvxuzi","kncoy","vfsmtnv","vtbuyel","avljtt","dkmukz","iwbtldi","ydeav","wrndm","nzobzhk","dsyzo","awhban","eawszkk","ijyqhxf","undht","prdnhwz","ondskn","clvpq","rhpwv","kclhfs","bhayx","lrzrr","snxkh","bqasx","nirsvq","jsbazqg","ikvkp","rkyui","ghnosl","eueeofr","ytflvxl","mdyni","sfrzfz","xoocttw","ytsyu","zysfjyr","xldgvou","mgpat","ewdny","ajzhaj","ouceh","uwneqof","vscci","ykymuh","ptpcw","wxlkqj","chxgq","xpvlr","uudqcz","cyqdtid","ytquhd","qfpxklg","laxcrip","kiufpl","lrkfyg","ciema","rlxedyp","rkucvkk","nkcrgbj","klbxqko","dugjzas","xoldmxq","qsbrf","asqykc","smtxr","dhfej","lvcghgc","sxrkdlj","uhsgytf","ulnia","sjxpne","zcdyx","mxdfpcx","mepjm","hnetd","ammoin","eisyjs","lgqcels","rfqxlma","ihgwyzi","fvlhfty","taccqkm","bxhgtze","qwhxi","yhzijhc","cqyljwp","lknzjk","urnhory","mpbvb","oezrpfi","fhvejwc","tlaizfz","oenbwib","bhxati","fkvamn","hfzeb","xlrzet","yvtutkn","bglozg","ukwstz","fdiltmr","uxxzuw","kzgtdhu","qlhas","qioqqks","jksihg","ewjqitq","apgbp","rckid","enylbr","xvtysp","rpxciwd","pricrse","jsprztx","cgyey","yuofzbo","dfdaeq","gyokh","hhqevjt","mqypn","cfaxg","encwy","bquytb","cyfmpmj","rzwmi","zrjdqj","quguqa","xukzu","moxdyhx","lyxmuhm","nsgxkd","qyyek","hbtxhff","junzq","sbuqpxc","yoxktfx","digsr","aqgyl","qpcovak","msfwv","ywvzk","mvohe","ybjutg","ubahkka","cmmhhho","dgiosg","pgelk","yawdsop","ezhnk","lbffev","krcjne","xzvdpw","rphbd","pkneg","jylhtli","bqipeh","nnhukkb","iykjt","gxjrux","abari","keprn","cqxwl","ebvbfyk","tzloo","drlzu","jictk","xsfavcj","uglgdv","hedok","yuuem","hphoyfj","yxaknq","dnbbsux","ivlmmzp","bfwcr","ptntck","aacuifc","nrsir","duqptp","qnztj","nwdpl","veseco","uuvpuxg","qjwfc","bstin","idddeh","jwlppaf","qzdusg","xyceyr","gvopxx","mamxjlk","rueygkh","nuqja","wcmkf","cogcp","neqxquu","cxaoj","xutjzrb","mwdcebq","btwebi","szutpx","xagjs","brstkv","mlqhta","gugoa","ftlbbns","crcwh","rfhet","mfjla","oqcsl","jekqnj","vgeajca","xnssuq","gnaljjv","fbixzzm","aqxrs","ufqir","nwnyl","hiaond","wkisqgr","bijlblu","vyers","hqgvig","whldj","epgpj","hprnmmo","gviblwm","wmdpusz","dslsyj","pmmukm","tdwfwtr","oueenfh","mvwhjff","chvmdz","tsjpi","ldxbj","uoouafw","vqfepoj","qcexnr","cuwvlee","yspakx","dblnshp","vsdrzs","dbmuyxc","fhjcae","imizb","rplozfx","zwkmciw","dosjood","wloimxw","juzov","lscuv","opnkkr","bdpvwbr","kzahm","nexuo","cxyelnt","kyeufv","iximegv","rowit","xoqejla","ihfqwdv","dosrcx","ovrcy","bcityx","pqkkbpm","fmnpj","kravr","uhnnznv","fswtlgq","bkzqxn","basricv","hdtyx","pmxsh","dkledd","zoahn","vdlbkfi","kjbrmci","ynbaza","pztdz","pdapon","zadkgd","nbvmg","vtaaxk","bhesumw","mokmic","vbeigw","sotwp","qvbdsxx","yqzpjj","jmslj","cmdudg","hpqytf","gfncgmm","xqefn","xztol","lydpt","nmdvvoj","hxxpqo","pjhkaj","xijjxnz","emglbs","kaovka","vhtniz","dypxhqb","skvqlyy","pwyft","volotb","zvmxeqj","bdpfie","maodqzl","jnbfskh","pnsjvr","mgvyuq","ozijn","sbpsgp","zsdke","eohunik","kioxj","yabmzm","psfqszv","gkbwo","gozjpdd","etonmuq","qjcdijx","rmqee","nbzgpav","mhuhjr","baaqhu","ndixcvn","urlophj","dtghc","igrdj","qvgnsci","iapjpsj","wlttkfu","npndkq","fmvkiad","qwrjznb","uhdpn","asivk","zfehgo","yavxwbk","ndzttmt","xkechm","lfnkrz","cggzc","bcjzv","femxnag","zisnaz","gopsjc","qeneul","uaprpt","uncrur","oisdh","cskbi","thtdel","chcetlp","jagjgzu","ibsfavi","ikxpru","lucfwm","rgytseg","grdlrd","vicbr","beqonzd","izlvw","ezpusur","ayaegkq","gjhhr","hxfntee","hvjcvr","rwmrq","kjhocfu","mnnyvrm","lxgiybl","cvpmurc","mazjd","eoqvp","yxagszg","mdwrn","nupcz","metfjsk","owwzsl","xbhwpqk","kkpbw","jvatw","fquloxu","spmkvi","dvdaok","fqleelx","xybsm","vefaau","iatanru","ozomoaq","sbpyaqa","odaum","rathdy","knfdfxl","nlxpv","pmmkly","dpetxww","kywip","eftvbj","acwsn","sjihom","ervpee","wwvga","ljdsid","qqefm","vuqytcz","xvucay","qyswmws","plaepq","ucrfzw","vpztpg","qajhi","aqeux","ejtnzwf","zjdsic","jqhyby","pfalnr","duvob","wfnqjtj","llzam","pzuzl","tkdydxs","otlzmkr","tbings","vudch","qxrfalx","kftmgu","jksph","rrjniw","mquobj","qyzregb","jhwlynl","hsaxnru","vlowon","oojxj","phpdck","korga","wgxkjda","yvkldbm","jcxhire","uevlxi","kwels","pryjff","jvwbv","ftxdpb","wxugmo","ufcud","qslpkon","tcgfcgj","mzfrkxk","ldzjmsr","kgledx","suiuoz"};
    int len = minimumLengthEncoding(words);
    cout << "len = " << len << endl;

    return 0;
}//end main
