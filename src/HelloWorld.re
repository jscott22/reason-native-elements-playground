open BsReactNative;

module App = {
  let component = ReasonReact.statelessComponent("HelloWorld");

  let make = (_children) => {
    ...component,
    render: _self =>
      <View>
        <RNE.Text headingMode=H1>(ReasonReact.string("Hello World!"))</RNE.Text>
      </View>
  };
};

let app = () => <App />;
