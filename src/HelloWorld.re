open BsReactNative;

module App = {
  let component = ReasonReact.statelessComponent("HelloWorld");
  let make = _children => {
    ...component,
    render: _self =>
      <View>
        <View>
          <RNE.Text headingMode=H1>
            (ReasonReact.string("Heading 1"))
          </RNE.Text>
        </View>
        <View>
          <RNE.Text headingMode=H2>
            (ReasonReact.string("Heading 2"))
          </RNE.Text>
        </View>
        <View>
          <RNE.Text headingMode=H3>
            (ReasonReact.string("Heading 3"))
          </RNE.Text>
        </View>
        <View>
          <RNE.Text headingMode=H4>
            (ReasonReact.string("Heading 4"))
          </RNE.Text>
        </View>
        <View>
          <RNE.Text headingMode=H4>
            (ReasonReact.string("Normal Text"))
          </RNE.Text>
        </View>
      </View>,
  };
};

let app = () => <App />;
